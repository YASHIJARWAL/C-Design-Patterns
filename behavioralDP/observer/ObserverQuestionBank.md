Yes. Since you're practicing **design patterns by writing the code yourself**, let's do these progressively rather than giving you solutions immediately.

## Observer Pattern — Practice Questions

### 🟢 Level 1 — Basic

**Q1. Weather Station**

Create a weather monitoring system.

* `WeatherStation` → Subject
* `Display` → Observer
* When temperature changes, all displays should be notified.
* Create at least **two displays**.
* `WeatherStation` should have:

  * `subscribe()`
  * `unsubscribe()`
  * `notify()`
  * `setTemperature()`

**Goal:** Recreate the basic Observer structure without looking at the boilerplate.

---

### 🟢 Q2. YouTube Channel

Create a YouTube notification system.

A `YouTubeChannel` can have multiple subscribers.

```text
YouTubeChannel
      |
      | notify
      ↓
 ┌────┼────┐
 ↓    ↓    ↓
User  User  User
```

Requirements:

* `Subscriber` should be an interface.
* `subscribe()`
* `unsubscribe()`
* `uploadVideo()`
* Every subscriber receives the video title.

Example:

```text
Tech Channel uploaded: "Observer Pattern Explained"

Rahul received notification
Yash received notification
Aman received notification
```

---

### 🟡 Q3. Stock Market

Create a stock-price notification system.

A `Stock` is the **Subject**.

Different investors are **Observers**.

When the stock price changes:

```text
Stock: AAPL
Price: $180 → $185
```

all investors should receive:

```text
Investor 1: AAPL price changed to $185
Investor 2: AAPL price changed to $185
```

Requirements:

* `StockObserver`
* `Stock`
* `Investor`
* `subscribe()`
* `unsubscribe()`
* `setPrice()`

**Extra challenge:** Pass both the stock name and price to `update()`.

---

### 🟡 Q4. Order Tracking

Build an e-commerce order notification system.

The `Order` is the Subject.

Different systems observe it:

```text
             Order
               |
       ┌───────┼────────┐
       ↓       ↓        ↓
    Email    SMS      Logger
```

When:

```cpp
order.setStatus("SHIPPED");
```

all observers should receive:

```text
Order status changed to SHIPPED
```

Then test:

```text
PLACED
   ↓
CONFIRMED
   ↓
SHIPPED
   ↓
DELIVERED
```

---

### 🟡 Q5. News Agency

Create a news publishing system.

`NewsAgency` → Subject

Observers:

* `EmailSubscriber`
* `MobileSubscriber`
* `TVChannel`

When a breaking news article is published:

```cpp
agency.publishNews("Major earthquake reported...");
```

all observers should be notified.

**Extra challenge:** Each observer should format the notification differently.

For example:

```text
EMAIL:
Breaking News: Major earthquake reported...

MOBILE:
🔔 Breaking News

TV:
NEWS ALERT: Major earthquake reported...
```

---

### 🔴 Q6. Chat Application

Design a chat notification system.

A `ChatRoom` is the Subject.

Users are Observers.

When one user sends:

```cpp
chatRoom.sendMessage("Hello everyone!");
```

all subscribed users should receive it.

But introduce one rule:

> **The sender should NOT receive their own message.**

So:

```text
Yash sends: "Hello"

Rahul: received "Hello"
Aman: received "Hello"
Yash: ❌ don't notify
```

This is a good exercise because you'll need to think about **what information `notify()` needs**.

---

### 🔴 Q7. Multiplayer Game

Create a game event notification system.

`Game` is the Subject.

Observers:

```text
AchievementSystem
Leaderboard
Analytics
NotificationSystem
```

When something happens:

```cpp
game.playerWon("Yash");
```

all observers should be notified.

Different events:

```text
PLAYER_WON
PLAYER_LOST
LEVEL_COMPLETED
ACHIEVEMENT_UNLOCKED
```

**Challenge:** Instead of passing just a string, create something like:

```cpp
struct GameEvent {
    string eventType;
    string playerName;
};
```

Then:

```cpp
update(GameEvent event)
```

---

### 🔴 Q8. Build Your Own Notification Framework

This is the most useful one for you.

Design:

```text
NotificationManager
        |
        +------ Observer
        |          |
        |       Email
        |       SMS
        |       Push
        |
        +------ subscribe()
        +------ unsubscribe()
        +------ notify()
```

Requirements:

1. Use an abstract `Observer` interface.
2. Support multiple observers.
3. Dynamically subscribe/unsubscribe.
4. Send a notification message.
5. Add a new notification type **without modifying `NotificationManager`**.

Then add:

```cpp
WhatsAppNotification
```

without changing the existing framework.

---

## 🧠 Final Challenge

Don't code this immediately.

Suppose you have:

```text
Stock Market
       |
       ↓
    Stock
       |
 ┌─────┼─────┐
 ↓     ↓     ↓
App   Email  SMS
```

The stock changes from:

```text
₹100 → ₹105
```

Answer these **before writing code**:

1. Who is the **Subject**?
2. Who is the **Observer**?
3. What should `update()` contain?
4. Who maintains the list of observers?
5. Who calls `update()`?
6. Should the Observer know about the Subject?
7. What happens when an observer unsubscribes?
8. If you add `WhatsAppObserver`, which existing class should **not** need modification?

If you can answer those 8 correctly, you've understood the core of Observer rather than just memorizing the code.

**I'd recommend doing Q1 → Q2 → Q4 → Q6 → Q8 in that order.**
