Absolutely. Since you're practicing GoF patterns in C++, here are **10 Command Pattern coding questions**, arranged from basic → interview-level. I’d recommend solving them **without looking at the solution first**.

### Level 1 — Understand the Pattern

**Q1. Remote Control — One Command**

Create a remote control system for a **Light**.

Requirements:

* `Command` interface with `execute()`.
* `Light` receiver with `turnOn()`.
* `LightOnCommand` as ConcreteCommand.
* `RemoteControl` as Invoker.
* Client should wire everything together.

Expected flow:

```text
RemoteControl → Command → Light
```

---

**Q2. Light On / Light Off**

Extend Q1 to support:

* `LightOnCommand`
* `LightOffCommand`

The remote should be able to switch between commands.

Add:

```cpp
setCommand(...)
pressButton()
```

The `RemoteControl` should have **no knowledge of the Light class**.

---

**Q3. Undo Command**

Modify Q2 to support:

```cpp
execute()
undo()
```

For example:

```text
pressButton()
    → Light ON

pressUndo()
    → Light OFF
```

Think carefully about **where the undo logic belongs**.

---

### Level 2 — Multiple Commands

**Q4. Smart Home Remote**

Create a smart-home remote supporting:

* Light ON/OFF
* Fan ON/OFF
* AC ON/OFF

Requirements:

```cpp
Command
   ↑
LightOnCommand
LightOffCommand
FanOnCommand
FanOffCommand
ACOnCommand
ACOffCommand
```

The Invoker should work with **any Command**, without knowing the concrete command.

---

**Q5. Macro Command**

Create a `MacroCommand`.

A macro should execute multiple commands sequentially.

Example:

```text
MovieMode
    ↓
LightOff
    ↓
ACOn
    ↓
TVOn
    ↓
SoundSystemOn
```

Your `MacroCommand` should itself implement:

```cpp
Command
```

Hint: it will need something like:

```cpp
vector<unique_ptr<Command>>
```

---

### Level 3 — Realistic Problems

**Q6. Text Editor Undo/Redo**

Build a simple text editor using Command.

Commands:

```text
InsertTextCommand
DeleteTextCommand
```

The editor should support:

```cpp
execute()
undo()
```

Example:

```text
Insert "Hello"
Insert " World"
Delete "World"

Undo → restores World
Undo → removes World
Undo → removes Hello
```

Use a **stack of commands** for history.

---

**Q7. Bank Transaction System**

Create a banking system using Command.

Commands:

```text
DepositCommand
WithdrawCommand
TransferCommand
```

The `BankAccount` should be the Receiver.

Support:

```cpp
execute()
undo()
```

Example:

```text
Deposit ₹1000
Withdraw ₹300

Undo
→ ₹300 is deposited back
```

The important part is to design the commands so that **each command knows how to reverse its own operation**.

---

### Level 4 — Interview-Level

**Q8. Job Queue System**

Build a command-based job processing system.

Different commands:

```text
SendEmailCommand
GenerateReportCommand
BackupDatabaseCommand
```

The `JobQueue` acts as an Invoker.

Requirements:

* Add commands to a queue.
* Execute commands sequentially.
* Commands must be polymorphic.
* The queue should not know the concrete command types.

Expected architecture:

```text
Client
  |
  v
JobQueue
  |
  v
Command
 / | \
Email Report Backup
  |
  v
Receiver
```

---

**Q9. Transactional Order System**

Design an order-processing system using Command.

Commands:

```text
CreateOrderCommand
ProcessPaymentCommand
ShipOrderCommand
CancelOrderCommand
```

Each command should have:

```cpp
execute()
undo()
```

Example:

```text
Create Order
      ↓
Process Payment
      ↓
Ship Order
```

If shipping fails, undo the previous operations.

Think about:

* Command
* ConcreteCommand
* Receiver
* Invoker
* Command history

This is a good question for understanding **Command + undo/rollback**.

---

### Level 5 — Advanced Interview Question

**Q10. Command Pattern with Logging and Replay**

Build a system where every command executed by the user is recorded.

Example:

```text
User
 ↓
Invoker
 ↓
Command
 ↓
Receiver
```

Commands:

```text
MoveCommand
AttackCommand
HealCommand
```

Each command should contain the information necessary to replay itself.

For example:

```cpp
MoveCommand(player, 10, 20);
```

means:

```text
Move player to (10,20)
```

Your system should support:

```cpp
execute()
undo()
log()
replay()
```

The final requirement is:

```text
User executes 5 commands
        ↓
Commands stored in history
        ↓
Clear current state
        ↓
Replay all commands
        ↓
State reconstructed
```

This one tests whether you actually understand **why Command is useful**, rather than just knowing its boilerplate.

### Recommended order

For your current learning stage, I'd do:

```text
Q1 → Q2 → Q3
          ↓
       Q4 → Q5
          ↓
       Q6 → Q7
          ↓
       Q8 → Q9 → Q10
```

**Q1–Q3** establish the pattern, **Q4–Q7** test whether you can design it yourself, and **Q8–Q10** are where Command starts becoming useful in real system-design scenarios.
