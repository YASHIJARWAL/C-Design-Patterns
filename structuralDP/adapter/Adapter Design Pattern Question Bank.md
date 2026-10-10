Here are **10 Adapter Pattern coding questions**, arranged from basic → interview-level. I’ll keep the pattern **unnamed in the question** so you have to identify where the adapter belongs.

### Level 1 — Basic

**1. Payment Gateway**
You have a client that expects:

```cpp
PaymentProcessor::pay()
```

An existing third-party class provides:

```cpp
ThirdPartyPayment::makePayment()
```

Implement the required classes so the client can use `ThirdPartyPayment` without modifying it.

---

**2. Media Player**

Your application expects:

```cpp
MediaPlayer::play()
```

But an existing library provides:

```cpp
LegacyPlayer::startAudio()
```

Make the existing library usable through the application's expected interface.

---

**3. Temperature Sensor**

Your monitoring system expects:

```cpp
TemperatureSensor::getTemperature()
```

An old sensor provides:

```cpp
OldSensor::readCelsius()
```

Create the necessary classes so the monitoring system can work with the old sensor.

---

### Level 2 — Multiple Adapters

**4. Notification System**

Your application expects:

```cpp
Notifier::send(string message)
```

You have three existing systems:

```cpp
EmailService::sendEmail(string message)
SMSService::sendSMS(string message)
SlackService::postMessage(string message)
```

Implement the design so the client only depends on `Notifier`.

The client should be able to switch between Email, SMS, and Slack without changing its code.

---

**5. Database Interface**

Your application expects:

```cpp
Database::executeQuery(string query)
```

Existing libraries provide:

```cpp
MySQLClient::runQuery(string query)
PostgresClient::execute(string query)
MongoClient::runCommand(string command)
```

Design the classes so all three can be used through a common interface.

---

**6. File Storage**

Your application expects:

```cpp
Storage::upload(string file)
Storage::download(string file)
```

Existing implementations provide:

```cpp
AWSStorage::putObject(string file)
AWSStorage::getObject(string file)

AzureStorage::uploadBlob(string file)
AzureStorage::downloadBlob(string file)
```

Implement the design without modifying either third-party class.

---

### Level 3 — Interview Style

**7. Logger Integration**

Your application expects:

```cpp
Logger::log(string message)
Logger::error(string message)
```

But a legacy logging library provides:

```cpp
LegacyLogger::writeInfo(string message)
LegacyLogger::writeError(string message)
```

Requirements:

* Don't modify `LegacyLogger`.
* Client must depend only on `Logger`.
* Use smart pointers.
* Demonstrate the complete flow in `main()`.

---

**8. Legacy Authentication**

Your modern application expects:

```cpp
Authenticator::authenticate(string username, string password)
```

An old authentication system provides:

```cpp
LegacyAuth::login(string username, string password)
```

Additionally, `LegacyAuth::login()` returns an integer:

```text
1 → success
0 → failure
```

Your new interface should return:

```cpp
bool
```

Implement the conversion.

This one tests whether you understand that an adapter can translate **both interface and return values**.

---

### Level 4 — Strong Interview Questions

**9. Networking Protocol Adapter**

Your application expects:

```cpp
NetworkClient::send(string data)
NetworkClient::receive()
```

You have two existing protocol implementations:

```cpp
HTTPClient::sendRequest(string data)
HTTPClient::getResponse()

UDPClient::sendPacket(string data)
UDPClient::receivePacket()
```

Requirements:

* Client should only know `NetworkClient`.
* HTTP and UDP classes cannot be modified.
* Use runtime polymorphism.
* Use `unique_ptr`.
* The client should be able to switch between HTTP and UDP.

---

**10. Adapter + Factory**

Design a system where the application expects:

```cpp
PaymentProcessor::processPayment(double amount)
```

Existing third-party systems are:

```text
Stripe      → charge(amount)
PayPal      → makePayment(amount)
Razorpay    → createPayment(amount)
```

Requirements:

1. Don't modify the third-party classes.
2. Create adapters for each payment provider.
3. Client depends only on `PaymentProcessor`.
4. Use `unique_ptr`.
5. Add a factory that returns the appropriate `PaymentProcessor`.
6. Adding another payment provider should require minimal changes to existing client code.

**This is the one I'd use as your interview-level practice question.**

### What you should be able to recognize

For every question, identify:

```text
Client
  ↓
Target Interface
  ↑
Adapter
  ↓
Existing/Incompatible Class
```

And remember the core test:

> **"I already have working code, but its interface doesn't match what my client expects."**

That's when Adapter should immediately come to mind.
