Absolutely. Since you're practicing the **Builder Pattern in C++**, I'll make these progressively harder and focused on the kind of implementation thinking you need for interviews.

### 🟢 Level 1 — Basic Builder

**Q1. Computer Builder**
Create a `Computer` using the Builder Pattern.

Required properties:

* `CPU`
* `RAM`
* `Storage`
* `GPU`

Requirements:

* `Computer` → Product
* `ComputerBuilder` → Builder
* `Director` should construct a standard gaming computer.
* Client should be able to display the final configuration.

---

**Q2. House Builder**
Build a `House` with:

* `walls`
* `doors`
* `windows`
* `roof`
* `garage`

Create:

* `House`
* `HouseBuilder`
* `Director`

The Director should be able to construct a **basic house** using a predefined sequence.

---

**Q3. Car Builder**
Create a `Car` with:

* Engine
* Wheels
* Color
* Transmission
* Sunroof

Create two concrete builders:

```text
SportsCarBuilder
FamilyCarBuilder
```

The same `Director` should be able to construct either type.

---

### 🟡 Level 2 — Builder Understanding

**Q4. Pizza Builder**
Create a `Pizza` using Builder.

Properties:

* Size
* Crust
* Cheese
* Sauce
* Toppings

Requirements:

```text
Small Pizza
Large Pizza
Vegetarian Pizza
```

The client should be able to construct different pizzas without directly manipulating the `Pizza` object's properties.

---

**Q5. HTTP Request Builder** ⭐

Create an `HTTPRequest` object containing:

* HTTP method
* URL
* Headers
* Query parameters
* Body
* Timeout

Example conceptual usage:

```cpp
HTTPRequest request =
    HTTPRequestBuilder()
        .setMethod("POST")
        .setURL("/users")
        .setHeader("Content-Type", "application/json")
        .setBody("{...}")
        .setTimeout(30)
        .build();
```

**Do not use a Director.**

This is important because it introduces the **modern/fluent Builder style** commonly seen in real code.

---

**Q6. Database Connection Builder**

Create a `DatabaseConnection` with:

* Host
* Port
* Username
* Password
* Database name
* Connection pool size
* SSL enabled

Requirements:

* Some properties should have **default values**.
* The client should only specify the properties it wants to change.
* Use method chaining.

Example:

```cpp
DatabaseConnection connection =
    DatabaseConnectionBuilder()
        .setHost("localhost")
        .setPort(5432)
        .setDatabase("users")
        .enableSSL()
        .build();
```

---

### 🔴 Level 3 — Interview-Level

**Q7. REST API Request Builder** ⭐⭐

Build a generic API request:

```text
APIRequest
├── method
├── URL
├── headers
├── query parameters
├── path parameters
├── body
├── timeout
└── retry count
```

Requirements:

* Use `unordered_map` for headers and parameters.
* Support method chaining.
* Provide sensible defaults.
* Prevent building an invalid request if the URL is missing.

Think about:

```cpp
.build()
```

throwing an exception when required information is absent.

---

**Q8. Server Configuration Builder** ⭐⭐

Create a `ServerConfig` object containing:

```text
host
port
maxConnections
threadPoolSize
timeout
enableLogging
enableTLS
certificatePath
```

Requirements:

1. `host` and `port` are mandatory.
2. Other fields have defaults.
3. TLS certificate must be provided if TLS is enabled.
4. Use Builder Pattern.
5. `build()` should validate the configuration.

This tests whether you understand **why Builder is useful**, rather than just knowing its class structure.

---

### 🔥 Level 4 — Advanced

**Q9. Thread-Safe Immutable Configuration Builder** ⭐⭐⭐

Create:

```text
ApplicationConfig
```

with:

```text
databaseURL
port
workerThreads
cacheSize
loggingEnabled
debugMode
```

Requirements:

* `ApplicationConfig` should be immutable after construction.
* Builder modifies temporary state.
* `build()` creates the final configuration.
* Use `unique_ptr` where appropriate.
* Multiple builders should be usable independently.

Think carefully about **ownership** and **object lifetime**.

---

**Q10. Network Packet Builder** ⭐⭐⭐

Create a `NetworkPacket` containing:

```text
sourceIP
destinationIP
sourcePort
destinationPort
protocol
payload
TTL
checksum
```

Create builders for:

```text
TCPPacketBuilder
UDPPacketBuilder
HTTPPacketBuilder
```

Requirements:

* Common construction steps should be represented through a Builder abstraction.
* Each concrete builder can customize the packet.
* Director should be capable of constructing standard TCP/UDP packets.
* Validate mandatory fields.
* Use appropriate C++ smart pointers.
* Display the final packet.

This one combines **Builder + polymorphism + networking concepts**, so it's a good final exercise.

---

### Recommended order for you

Given that you're currently learning the GoF patterns, I'd do:

```text
Q1 → Q2 → Q3
          ↓
Q4 → Q5 → Q6
          ↓
Q7 → Q8
          ↓
Q9 → Q10
```

**Don't jump to Q10 immediately.** The key progression is:

```text
Basic Builder
     ↓
Builder + Director
     ↓
Multiple Concrete Builders
     ↓
Fluent Builder
     ↓
Validation + defaults
     ↓
Smart pointers + immutability
     ↓
Real-world system design
```

I'd particularly recommend **Q1 → Q3 → Q5 → Q7 → Q10** if your goal is interview preparation rather than exhaustive practice.
