Here are **10 Proxy Pattern coding questions**, arranged from basic → interview-level. I won't label which proxy type each question represents, so you have to identify the design yourself.

### 🟢 Level 1 — Basic

**1. Lazy Object Creation**
Create a `Service` interface with `operation()`. `RealService` performs an expensive initialization. Create a `Proxy` such that `RealService` is created **only when `operation()` is actually called**.

---

**2. Access Control**
Create:

```cpp
class User {
    string role;
};
```

Create a `Service` that performs `deleteData()`.

The proxy should allow the operation only when the user's role is `"ADMIN"`. Otherwise print:

```text
Access Denied
```

---

**3. Logging Proxy**
Create a `Subject` with:

```cpp
void operation();
```

The proxy should print:

```text
Request received
Operation started
Operation completed
```

around the real object's `operation()`.

---

### 🟡 Level 2 — Intermediate

**4. Caching Proxy**
Create a `DataService` with:

```cpp
string getData(int id);
```

The real service performs an expensive operation.

The proxy should:

* Check whether `id` exists in a cache.
* Return cached data if available.
* Otherwise call `RealService`.
* Store the result in the cache.

Example:

```text
First request:
Fetching data from server...

Second request:
Returning data from cache...
```

---

**5. Image Loading Proxy**
Create:

```cpp
Image
RealImage
ImageProxy
```

`RealImage` should simulate loading a large image.

The proxy should **not load the image during construction**.

Only when:

```cpp
display()
```

is called should the real image be created and displayed.

---

**6. Authentication Proxy**
Create a `Service` with:

```cpp
void getAccountDetails();
void transferMoney();
```

Create a proxy that receives:

```cpp
username
password
```

and validates them before forwarding requests to `RealService`.

Invalid credentials should never reach the real service.

---

### 🟠 Level 3 — Interview Level

**7. Rate-Limiting Proxy**
Create:

```cpp
Service
RealService
Proxy
```

The proxy should allow only **3 requests**.

After 3 requests:

```text
Rate limit exceeded
```

The fourth and subsequent requests should not reach `RealService`.

---

**8. Remote Service Proxy**
Assume `RealService` represents a service running on another machine.

Create a proxy that exposes:

```cpp
void sendRequest(string request);
```

The proxy should simulate:

```text
Client
  ↓
Proxy
  ↓
Network Call
  ↓
Remote Service
```

The client should never directly interact with the remote service.

---

### 🔴 Level 4 — Strong Interview Questions

**9. Multi-Level Proxy**

Create a system:

```text
Client
   ↓
AuthenticationProxy
   ↓
CachingProxy
   ↓
LoggingProxy
   ↓
RealService
```

All proxies must implement the same `Subject` interface.

Requirements:

* Authentication happens first.
* Cache is checked next.
* Logging happens around the actual request.
* Real service is called only when required.
* Client should interact only with the outermost proxy.

Use `unique_ptr` for ownership.

---

**10. Proxy vs Decorator Challenge**

Create a `FileService`:

```cpp
void readFile(string filename);
void writeFile(string filename);
void deleteFile(string filename);
```

Build a proxy that:

* Checks user permissions.
* Prevents unauthorized operations.
* Logs denied requests.
* Forwards authorized requests to `RealFileService`.

Then modify the system so that **caching/logging can be added independently without becoming part of the access-control proxy**.

Your final design should clearly separate:

```text
Access Control → Proxy
Additional Behavior → Decorator
Actual Operation → RealSubject
```

### ⭐ For your current pattern preparation

I'd recommend solving **1 → 2 → 4 → 5 → 7 → 9 → 10** first. If you can implement **#9 and #10 cleanly**, I'd consider your Proxy knowledge sufficient for typical LLD/interview questions.
