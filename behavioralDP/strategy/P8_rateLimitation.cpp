#include <iostream>
#include <memory>
#include <chrono>
#include <queue>
#include <deque>

using namespace std;

// ==================== Strategy Interface ====================

class RateLimiter {
public:
    virtual void rateLimiting() = 0;
    virtual ~RateLimiter() = default;
};

// ==================== Token Bucket ====================

class TokenBucketStrategy : public RateLimiter {
private:
    double tokens = 5;
    double capacity = 5;
    double refillRate = 1; // tokens per second

    chrono::steady_clock::time_point lastRefill =chrono::steady_clock::now();

public:
    void rateLimiting() override {

        auto now = chrono::steady_clock::now();

        double elapsed =chrono::duration<double>(now - lastRefill).count();

        // Refill tokens according to elapsed time
        tokens += elapsed * refillRate;

        // Don't exceed bucket capacity
        if (tokens > capacity)
            tokens = capacity;

        lastRefill = now;

        // Consume one token
        if (tokens >= 1) {

            tokens--;

            cout << "Request allowed - Token Bucket"<< endl;
        }
        else {

            cout << "Request rejected - Token Bucket"<< endl;
        }
    }
};

// ==================== Leaky Bucket ====================

class LeakyBucketStrategy : public RateLimiter {
private:
    queue<chrono::steady_clock::time_point> requests;

    int capacity = 5;
    int leakRate = 1; // requests per second

    chrono::steady_clock::time_point lastLeak =chrono::steady_clock::now();

public:
    void rateLimiting() override {

        auto now = chrono::steady_clock::now();

        double elapsed = chrono::duration<double>( now - lastLeak).count();

        // Calculate how many requests can leak
        int requestsToProcess =static_cast<int>(elapsed * leakRate);

        // Remove processed requests
        for (int i = 0;i < requestsToProcess && !requests.empty();i++) {
            requests.pop();
        }
        if (requestsToProcess > 0)
            lastLeak = now;
        // Add current request if queue has space
        if (requests.size() < capacity) {
            requests.push(now);
            cout << "Request accepted into queue - "<< "Leaky Bucket"<< endl;
        }
        else {
            cout << "Request rejected - "<< "Leaky Bucket queue full"<< endl;
        }
    }
};

// ==================== Sliding Window ====================

class SlidingWindowStrategy : public RateLimiter {
private:
    deque<chrono::steady_clock::time_point> requests;

    int maxRequests = 5;
    int windowSize = 10; // seconds

public:
    void rateLimiting() override {

        auto now = chrono::steady_clock::now();

        // Remove requests outside the sliding window
        while (!requests.empty()) {

            auto elapsed =chrono::duration_cast<chrono::seconds>(now - requests.front()).count();

            if (elapsed >= windowSize)
                requests.pop_front();
            else
                break;
        }

        // Check request limit
        if (requests.size() < maxRequests) {

            requests.push_back(now);

            cout << "Request allowed - Sliding Window"<< endl;
        }
        else {

            cout << "Request rejected - Sliding Window"<< endl;
        }
    }
};

// ==================== Fixed Window ====================

class FixedWindowStrategy : public RateLimiter {
private:
    int requestCount = 0;
    int maxRequests = 5;

    int windowSize = 10; // seconds

    chrono::steady_clock::time_point windowStart =chrono::steady_clock::now();

public:
    void rateLimiting() override {

        auto now = chrono::steady_clock::now();

        auto elapsed =chrono::duration_cast<chrono::seconds>(now - windowStart).count();

        // Start a new fixed window
        if (elapsed >= windowSize) {

            requestCount = 0;
            windowStart = now;
        }

        // Check request limit
        if (requestCount < maxRequests) {

            requestCount++;

            cout << "Request allowed - Fixed Window"<< endl;
        }
        else {

            cout << "Request rejected - Fixed Window"<< endl;
        }
    }
};

// ==================== Context ====================

class StrategyProcessor {
private:
    unique_ptr<RateLimiter> rateLimiter;

public:

    StrategyProcessor(
        unique_ptr<RateLimiter> rateLimiter
    )
        : rateLimiter(move(rateLimiter)) {}

    void perform() {
        rateLimiter->rateLimiting();
    }

    void setStrategy(
        unique_ptr<RateLimiter> rateLimiter
    ) {
        this->rateLimiter = move(rateLimiter);
    }
};

// ==================== Main ====================

int main() {

    // Token Bucket
    StrategyProcessor processor(
        make_unique<TokenBucketStrategy>()
    );

    processor.perform();
    processor.perform();
    processor.perform();

    // Switch to Leaky Bucket
    processor.setStrategy(
        make_unique<LeakyBucketStrategy>()
    );

    processor.perform();
    processor.perform();
    processor.perform();

    // Switch to Fixed Window
    processor.setStrategy(
        make_unique<FixedWindowStrategy>()
    );

    processor.perform();
    processor.perform();
    processor.perform();

    // Switch to Sliding Window
    processor.setStrategy(
        make_unique<SlidingWindowStrategy>()
    );

    processor.perform();
    processor.perform();
    processor.perform();

    return 0;
}