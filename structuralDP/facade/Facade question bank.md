Absolutely. Since you're practicing **Facade specifically for interviews**, here are 10 coding questions progressing from basic → backend/system-design style.

### 🟢 Basic

1. **Computer Startup System**
   Create `CPU`, `Memory`, and `Disk` classes. Each has its own startup method. Create a `ComputerFacade` with `startComputer()` that performs the correct startup sequence.

2. **Home Theater System**
   Create `Amplifier`, `DVDPlayer`, `Projector`, and `Speaker` subsystems. Implement `watchMovie()` and `endMovie()` through a `HomeTheaterFacade`.

3. **Bank Account Operations**
   Create `AccountService`, `BalanceService`, and `TransactionService`. Build a `BankFacade` exposing:

   ```cpp
   deposit()
   withdraw()
   checkBalance()
   ```

   The client should interact only with the facade.

4. **Food Ordering System**
   Create `Inventory`, `Payment`, `Restaurant`, and `Delivery` classes. Implement:

   ```cpp
   FoodOrderFacade::placeOrder()
   ```

   that coordinates all four subsystems.

### 🟡 Intermediate

5. **File Upload System**
   Create:

   ```text
   FileValidator
   FileCompressor
   FileUploader
   MetadataService
   ```

   Build `FileUploadFacade::upload()` that hides the complete upload workflow.

6. **Authentication System**
   Create:

   ```text
   UserService
   PasswordValidator
   TokenService
   SessionService
   ```

   Implement:

   ```cpp
   AuthFacade::login(username, password)
   ```

   The client should not directly interact with the individual services.

7. **E-Commerce Checkout**
   Create:

   ```text
   Cart
   Inventory
   Payment
   Order
   Notification
   ```

   Implement:

   ```cpp
   CheckoutFacade::checkout()
   ```

   which coordinates the complete purchase flow.

### 🔴 Backend / System Design Style

8. **API Request Processing Facade**
   Create:

   ```text
   RequestParser
   Authentication
   Authorization
   RateLimiter
   Logger
   ResponseBuilder
   ```

   Implement:

   ```cpp
   APIFacade::processRequest()
   ```

   that exposes one simple entry point to the client.

9. **Database Access Facade**
   Create:

   ```text
   ConnectionPool
   QueryBuilder
   DatabaseExecutor
   TransactionManager
   ```

   Implement:

   ```cpp
   DatabaseFacade::executeQuery()
   ```

   so that callers don't need to understand connection acquisition, transaction handling, query execution, and connection release.

10. **Microservice Order Processing** ⭐
    Create independent services:

```text
UserService
InventoryService
PaymentService
OrderService
NotificationService
```

Implement:

```cpp
OrderFacade::placeOrder()
```

Flow:

```text
Client
   ↓
OrderFacade
   ↓
User validation
   ↓
Inventory check
   ↓
Payment
   ↓
Create Order
   ↓
Send Notification
```

Add failure handling so that if payment fails, the order isn't created.

### What you should be able to recognize

When solving these, ask yourself:

> **"Does the client have to understand and coordinate several subsystem objects?"**

If **yes → Facade is a candidate.**

And don't accidentally turn it into **Template Method**: your Facade should generally **coordinate existing subsystem objects**, not define an inheritance-based algorithm with overridable steps.
