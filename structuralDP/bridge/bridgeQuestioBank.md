# Bridge Design Pattern — 10 Coding Questions

## 1. Notification System

Design a notification system where different notification types can work with different delivery mechanisms.

- Notification types: `Alert`, `Reminder`
- Delivery mechanisms: `Email`, `SMS`
- Adding a new notification type should not require modifying delivery mechanisms.

---

## 2. Remote Control

Design a remote-control system.

- Remotes: `BasicRemote`, `AdvancedRemote`
- Devices: `TV`, `Radio`
- Both remote types should work with both devices.
- Support operations such as `powerOn()` and `powerOff()`.

---

## 3. Payment System

Design a payment system supporting:

- Payment types: `OnlinePayment`, `RecurringPayment`
- Payment providers: `Stripe`, `Razorpay`
- A new payment provider should be addable without modifying payment types.

---

## 4. Operating System + UI

Design a UI framework where:

- UI types: `DesktopUI`, `MobileUI`
- Operating systems: `Windows`, `Linux`, `Android`
- Each UI should be able to work with different OS implementations.

---

## 5. Database Access

Design a database access layer supporting:

- High-level operations: `UserRepository`, `OrderRepository`
- Database implementations: `MySQL`, `PostgreSQL`
- Repositories should not directly depend on a specific database.

This one is particularly relevant to backend development.

---

## 6. Logging Framework

Design a logging framework supporting:

- Logger types: `ApplicationLogger`, `AuditLogger`
- Output mechanisms: `Console`, `File`, `Cloud`
- Both logger types should be able to use any output mechanism.

Example:

```text
ApplicationLogger → Console
ApplicationLogger → File
AuditLogger       → Console
AuditLogger       → Cloud
```

---

## 7. Message Processing

Design a message-processing system.

High-level processors:

```text
TextMessageProcessor
ImageMessageProcessor
```

Underlying transports:

```text
TCPTransport
HTTPTransport
UDPTransport
```

A processor should be able to work with any transport.

---

## 8. Cloud Storage

Design a storage abstraction supporting:

- Storage operations: `FileStorage`, `BackupStorage`
- Providers: `AWS`, `Azure`, `GCP`

For example:

```text
FileStorage   → AWS
FileStorage   → Azure
BackupStorage → AWS
BackupStorage → GCP
```

Adding `GoogleCloudStorage` should not require modifying the storage abstractions.

---

## 9. Report Generation

Design a report-generation system.

Report types:

```text
SalesReport
EmployeeReport
```

Rendering mechanisms:

```text
PDFRenderer
HTMLRenderer
ExcelRenderer
```

Any report should be renderable using any renderer.

---

## 10. Networking Protocol Stack ⭐

Design a networking abstraction.

High-level communication types:

```text
ReliableConnection
FastConnection
```

Underlying protocols:

```text
TCP
UDP
```

Requirements:

- `ReliableConnection` should use TCP.
- `FastConnection` should be able to use UDP.
- The design should allow another protocol to be introduced later.
- Avoid creating classes like:

```text
ReliableTCP
ReliableUDP
FastTCP
FastUDP
```

**Key Bridge test:** if you find yourself creating a Cartesian-product explosion of classes, Bridge is probably the solution.

---

## Recommended Order

Do:

**1 → 2 → 3 → 5 → 6 → 8 → 10**

For GoF practice, **#10 is particularly valuable** because it connects directly to networking and HLD.