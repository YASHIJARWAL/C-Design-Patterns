Sure. Since you're practicing the **GoF Visitor Pattern in C++**, I'll make these progressively harder. The first few focus on understanding the mechanics; later ones force you to understand **why Visitor exists**.

### 🟢 Level 1 — Understand the Pattern

**1. Shape Area Calculator**

Create:

```text
Shape
 ├── Circle
 ├── Rectangle
 └── Triangle
```

Create an `AreaVisitor` that calculates the area of each shape.

**Requirements:**

* `Shape` has `accept(Visitor&)`
* `Visitor` has `visit(Circle&)`, `visit(Rectangle&)`, `visit(Triangle&)`
* Store the dimensions inside each shape.
* Don't put `calculateArea()` inside the shapes.

---

**2. Shape Perimeter Visitor**

Using:

```text
Circle
Rectangle
Triangle
```

create a `PerimeterVisitor`.

The shapes should remain unchanged from Q1.

**Goal:** Understand how you can add a **new operation** without modifying the elements.

---

**3. Shape Information Visitor**

Create a visitor that prints information about each shape:

```text
Circle → Radius: 5
Rectangle → Width: 10, Height: 20
Triangle → Base: 5, Height: 10
```

Don't use `dynamic_cast`.

---

### 🟡 Level 2 — Multiple Visitors

**4. Employee Payroll System**

Create:

```text
Employee
 ├── Developer
 ├── Manager
 └── Intern
```

Each employee contains different information.

Create:

```text
SalaryVisitor
```

that calculates salary differently for each employee.

Then create:

```text
EmployeeReportVisitor
```

that prints employee information.

**Challenge:** Don't put salary calculation or report generation inside the employee classes.

---

**5. File System Visitor**

Create:

```text
FileSystemElement
 ├── File
 ├── Directory
 └── SymbolicLink
```

Create visitors:

```text
SizeVisitor
PermissionVisitor
PrintVisitor
```

For example:

```text
File → 500 KB
Directory → 2 GB
SymbolicLink → /home/user/file
```

The same elements must work with all three visitors.

---

### 🟠 Level 3 — Realistic Problems

**6. Shopping Cart**

Create:

```text
Product
 ├── Book
 ├── Electronics
 └── Clothing
```

Create:

```text
TaxVisitor
```

with different tax calculations for each product.

Then create:

```text
DiscountVisitor
```

with different discount rules.

**Important:** Products should not know anything about tax or discount logic.

---

**7. Compiler AST Visitor**

Create a very small expression tree:

```text
Expression
 ├── Number
 ├── Addition
 └── Multiplication
```

Example:

```text
(10 + 20) * 5
```

Create:

```text
EvaluationVisitor
```

that evaluates the expression.

Then create:

```text
PrintVisitor
```

that prints:

```text
((10 + 20) * 5)
```

This one is particularly useful because **AST visitors are a real-world use of the pattern.**

---

### 🔴 Level 4 — Think About Design

**8. Database Query Visitor**

Create:

```text
QueryNode
 ├── SelectNode
 ├── WhereNode
 └── JoinNode
```

Create:

```text
SQLVisitor
```

that converts the nodes into an SQL query.

For example:

```text
SelectNode
WhereNode
JoinNode
```

could produce something conceptually like:

```sql
SELECT ...
FROM ...
WHERE ...
JOIN ...
```

Then create another visitor:

```text
ValidationVisitor
```

that checks whether the query structure is valid.

---

**9. Network Packet Visitor**

Create:

```text
Packet
 ├── TCPPacket
 ├── UDPPacket
 └── HTTPPacket
```

Create:

```text
LoggingVisitor
SecurityVisitor
StatisticsVisitor
```

Each visitor performs a different operation on each packet type.

For example:

```text
LoggingVisitor → logs packet information
SecurityVisitor → checks security rules
StatisticsVisitor → collects packet statistics
```

The packet classes should contain **packet data**, not logging/security/statistics logic.

---

### 🔥 Level 5 — Interview-Level

**10. HTTP Request Processing**

Create:

```text
Request
 ├── GETRequest
 ├── POSTRequest
 └── DELETERequest
```

Create visitors:

```text
LoggingVisitor
AuthenticationVisitor
ValidationVisitor
MetricsVisitor
```

Your program should allow:

```cpp
Request& request = ...;

request.accept(loggingVisitor);
request.accept(authenticationVisitor);
request.accept(validationVisitor);
request.accept(metricsVisitor);
```

Each visitor should behave differently depending on whether the request is:

```text
GET
POST
DELETE
```

### Recommended order

Don't jump straight to #10.

```text
1 → 2 → 3
      ↓
4 → 5
      ↓
6 → 7
      ↓
8 → 9
      ↓
10
```

**For your current level, I'd start with #1 and have you write it yourself.** The important thing isn't memorizing `accept()` and `visit()`—it's understanding **why the operation belongs in the Visitor rather than the element.**
