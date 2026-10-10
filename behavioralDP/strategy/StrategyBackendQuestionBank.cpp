Since you're practicing **Strategy Pattern for backend/system-design interviews**, here are 10 coding problems that progressively move from basic Strategy usage to realistic backend scenarios.

### Level 1 — Core Strategy Pattern

**1. Payment Processing System**
Design a payment service supporting:

* Credit Card
* UPI
* Net Banking
* Wallet

Requirements:

* `PaymentStrategy` interface
* Each payment method implements the strategy
* `PaymentProcessor` should be able to switch payment methods at runtime.

**2. File Compression Service**
Build a compression service supporting:

* ZIP
* TAR
* GZIP

`CompressionService` should not know the implementation details of each compression algorithm.

---

### Level 2 — Backend-Oriented

**3. API Rate Limiter**

Design a `RateLimiter` supporting different algorithms:

* Fixed Window
* Sliding Window
* Token Bucket
* Leaky Bucket

Requirements:

```text
RateLimiter
    └── RateLimitStrategy
          ├── FixedWindowStrategy
          ├── SlidingWindowStrategy
          ├── TokenBucketStrategy
          └── LeakyBucketStrategy
```

The strategy should be replaceable without changing the API gateway code.

---

**4. Authentication Strategy**

Build an authentication service supporting:

* API Key
* JWT
* OAuth
* Basic Authentication

Input:

```text
Request
 ├── headers
 ├── token
 └── credentials
```

Your service should select the appropriate authentication strategy.

---

**5. Logging Strategy**

Build a backend logging system supporting:

* Console logging
* File logging
* Database logging
* Remote logging

Requirements:

* `LoggerStrategy`
* `Logger`
* Runtime switching of logging destination
* Different log levels: INFO, DEBUG, ERROR

---

### Level 3 — More Interview-Like

**6. Database Routing Strategy**

Design a database access layer that can route requests to:

```text
ReadWriteStrategy
       │
       ├── PrimaryDatabase
       ├── ReplicaDatabase
       └── LoadBalancedReplica
```

Requirements:

* Reads should be routed according to the selected strategy.
* Writes must go to the primary.
* Strategy should be replaceable at runtime.

**Bonus:** Add a strategy that routes reads based on replica latency.

---

**7. Cache Eviction Strategy**

Design a cache supporting different eviction policies:

* LRU
* LFU
* FIFO
* Random

Example:

```cpp
Cache cache(
    make_unique<LRUStrategy>()
);

cache.put("user:101", user);
cache.get("user:101");

cache.setStrategy(
    make_unique<LFUStrategy>()
);
```

Think carefully about **what belongs in `Cache` versus what belongs in the strategy**.

---

**8. Request Retry Strategy**

Design an HTTP client that supports different retry policies:

* No Retry
* Fixed Delay
* Exponential Backoff
* Exponential Backoff + Jitter

Example:

```text
HTTPClient
    |
    └── RetryStrategy
          ├── NoRetry
          ├── FixedRetry
          ├── ExponentialBackoff
          └── JitterRetry
```

The client shouldn't contain `if/else` logic for every retry algorithm.

---

### Level 4 — Strong System-Design Coding

**9. Load Balancing Strategy**

Build a load balancer supporting:

* Round Robin
* Random
* Least Connections
* Weighted Round Robin
* IP Hash

Example:

```text
LoadBalancer
      |
      └── LoadBalancingStrategy
             ├── RoundRobin
             ├── Random
             ├── LeastConnection
             └── WeightedRoundRobin
```

Given:

```text
Server A → 10 connections
Server B → 4 connections
Server C → 7 connections
```

`LeastConnectionStrategy` should select B.

**Bonus:** Make the strategy thread-safe.

---

**10. Message Delivery Strategy**

Design a notification/message delivery service supporting:

* Email
* SMS
* Push Notification
* Slack
* Webhook

But make the **delivery behavior itself** configurable.

For example:

```text
MessageService
      |
      └── DeliveryStrategy
             ├── ImmediateDelivery
             ├── RetryDelivery
             ├── BatchDelivery
             └── PriorityDelivery
```

Now you have **two independent dimensions**:

```text
Channel
  ├── Email
  ├── SMS
  └── Push

Delivery Strategy
  ├── Immediate
  ├── Retry
  └── Batch
```

This is a good exercise for understanding when **Strategy alone starts becoming insufficient and composition becomes important**.

---

### Recommended order for you

Given that you've already practiced basic examples like **Payment, Sorting, Navigation, Compression and Messaging**, don't redo those. I'd do:

**3 → 8 → 7 → 9 → 6 → 4 → 10**

The **Rate Limiter, Retry Strategy, Cache Eviction, Load Balancer and Database Routing** are particularly useful because they force you to think beyond simply creating an interface and three derived classes.

For each problem, try to implement it yourself with your current structure:

```cpp
class Strategy {
public:
    virtual void execute(...) = 0;
    virtual ~Strategy() = default;
};

class Context {
private:
    unique_ptr<Strategy> strategy;

public:
    Context(unique_ptr<Strategy> strategy)
        : strategy(move(strategy)) {}

    void setStrategy(unique_ptr<Strategy> strategy) {
        this->strategy = move(strategy);
    }
};
```

Then ask yourself: **"What behavior is actually varying here, and am I putting the right responsibility inside the Strategy?"** That's the key interview-level part of Strategy Pattern.
