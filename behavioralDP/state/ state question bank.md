Here are **10 State Pattern coding questions**, ordered from easy → interview-level. I’ll keep them **without solutions** so you can implement them yourself.

### Level 1 — Basic

**1. Traffic Light**

* States: `Red`, `Yellow`, `Green`
* `TrafficLight` is the Context.
* `change()` should behave differently depending on the current state.
* Implement transitions: `Red → Green → Yellow → Red`.

**2. Media Player**

* States: `Playing`, `Paused`, `Stopped`
* Context: `MediaPlayer`
* Operations:

  * `play()`
  * `pause()`
  * `stop()`
* Invalid operations should produce an appropriate message.

**3. Door**

* States: `Open`, `Closed`, `Locked`
* Operations:

  * `open()`
  * `close()`
  * `lock()`
  * `unlock()`
* Make state transitions happen based on these operations.

### Level 2 — Intermediate

**4. Vending Machine**

* States: `Idle`, `HasMoney`, `Dispensing`, `OutOfStock`
* Operations:

  * `insertMoney()`
  * `selectItem()`
  * `dispense()`
  * `refund()`
* The same operation should behave differently depending on the current state.

**5. ATM**

* States: `NoCard`, `CardInserted`, `Authenticated`, `Blocked`
* Operations:

  * `insertCard()`
  * `enterPin()`
  * `withdraw()`
  * `ejectCard()`
* After 3 incorrect PIN attempts, transition to `Blocked`.

**6. Order Processing**

* States: `Created`, `Paid`, `Shipped`, `Delivered`, `Cancelled`
* Operations:

  * `pay()`
  * `ship()`
  * `deliver()`
  * `cancel()`
* Prevent invalid transitions such as:

```text
Delivered → Cancelled
Shipped → Paid
Cancelled → Delivered
```

### Level 3 — Interview Level

**7. TCP Connection**

* States: `Closed`, `Listening`, `Connected`
* Operations:

  * `listen()`
  * `connect()`
  * `send()`
  * `close()`
* `send()` should only work when the connection is `Connected`.
* Implement valid state transitions.

**8. Document Workflow**

* States: `Draft`, `Review`, `Approved`, `Published`, `Rejected`
* Operations:

  * `submit()`
  * `approve()`
  * `reject()`
  * `publish()`
  * `edit()`
* The state should control which operations are allowed.

### Level 4 — Strong Interview Questions

**9. Elevator**

* States: `Idle`, `MovingUp`, `MovingDown`, `DoorOpen`
* Operations:

  * `requestFloor()`
  * `reachFloor()`
  * `openDoor()`
  * `closeDoor()`
* State transitions should happen internally rather than the client directly calling `setState()`.

**10. Online Payment Transaction**

* States:

```text
Created
   ↓
Processing
   ↓
Success
   ↓
Refunded
```

with failure possibilities:

```text
Processing → Failed
Failed → Retry
Success → Refunded
```

Implement:

```cpp
pay()
retry()
refund()
cancel()
```

The **state objects themselves should control valid transitions** where appropriate.

---

### 🎯 What I want you to focus on

For questions **1–6**, your existing boilerplate is enough:

```cpp
class State {
public:
    virtual void operation() = 0;
    virtual ~State() = default;
};
```

For **7–10**, don't simply do:

```cpp
context.setState(make_unique<State2>());
```

from `main()`.

Instead, aim for:

```cpp
context.connect();
context.send();
context.close();
```

where the **current state determines the next state**.

If you can implement **#4, #5, #6, #9 and #10 cleanly**, I'd consider your State Pattern knowledge **interview-ready**.
