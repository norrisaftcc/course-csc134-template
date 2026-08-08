# Software Engineering Principles Integration for CSC 134

## Badge Alignment
Directly supports badge requirements:
- **Software Development Practices**: Agile methodology
- **Object-Oriented Programming**: SOLID principles
- **Program Design and Implementation**: Engineering-first approach

---

## Week 9-10: Introduction to Agile Development
### "Your RPG as a Software Project"

**Core Agile Concepts:**
1. **User Stories** replace vague requirements
2. **Sprints** organize work into manageable chunks
3. **Retrospectives** improve process and code

### User Story Template for RPG Features:
```
As a [type of user]
I want [feature]
So that [benefit]
```

**Examples:**
- *As a player, I want to save my progress so that I can resume later*
- *As a player, I want to see my inventory so that I can manage items*
- *As a GM, I want to create NPCs so that I can populate the world*

### Sprint Planning (2-week cycles):
**Sprint 1 (Weeks 9-10):**
- Goal: Core game loop with saves
- Stories: Combat, inventory, file I/O
- AI Integration: Boilerplate generation

**Sprint 2 (Weeks 11-12):**
- Goal: Full OOP refactor
- Stories: Character classes, item system
- AI Integration: Class design assistance

### Daily Standup Questions (adapted for class):
1. What did I complete since last class?
2. What will I work on before next class?
3. What's blocking my progress?

---

## Week 11-12: Object-Oriented Design Principles
### "Building Maintainable Game Systems"

**The Journey from Procedural to OOP:**

### Week 11: Basic OOP Concepts
**Encapsulation Example:**
```cpp
// Bad (Week 1-8 style):
int playerHP = 100;
int playerMaxHP = 100;
string playerName = "Hero";
// HP can be set to invalid values anywhere!

// Good (Week 11+ style):
class Character {
private:
    int currentHP;
    int maxHP;
    string name;
public:
    void takeDamage(int damage) {
        currentHP = max(0, currentHP - damage);  // Can't go below 0
    }
    void heal(int amount) {
        currentHP = min(maxHP, currentHP + amount);  // Can't exceed max
    }
};
```

**AI Prompting for OOP:**
```
"I have player data: HP, maxHP, name, level, experience.
Create a Character class that:
- Prevents invalid HP values
- Automatically levels up at XP thresholds
- Follows encapsulation principles
Explain each design decision."
```

---

## Week 13-14: SOLID Principles
### "From Working Code to Professional Code"

### 1. Single Responsibility Principle (SRP)
**Before:**
```cpp
class Character {
    void attack() { /* combat logic */ }
    void saveToFile() { /* file I/O */ }
    void drawOnScreen() { /* graphics */ }
    // Too many responsibilities!
};
```

**After:**
```cpp
class Character { /* character data only */ };
class CombatSystem { /* handles combat */ };
class SaveManager { /* handles persistence */ };
class Renderer { /* handles display */ };
```

**Student Exercise:** "My Item class does too much. Help me split it using SRP."

### 2. Open/Closed Principle (OCP)
**Extending without Modifying:**
```cpp
// Bad: Have to modify switch for each new enemy
switch(enemyType) {
    case GOBLIN: /* goblin AI */
    case ORC: /* orc AI */
    // Adding new enemy = modifying this code
}

// Good: Polymorphism allows extension
class Enemy {
    virtual void act() = 0;
};
class Goblin : public Enemy {
    void act() override { /* goblin behavior */ }
};
// Adding new enemy = new class, no modifications
```

### 3. Liskov Substitution Principle (LSP)
**Why the Square/Rectangle Problem Matters:**
```cpp
// Seems logical but violates LSP:
class Rectangle {
    virtual void setWidth(int w) { width = w; }
    virtual void setHeight(int h) { height = h; }
};
class Square : public Rectangle {
    // Breaks expectations! Setting width changes height
    void setWidth(int w) override { width = height = w; }
};
```

**RPG Application:** "Should Warrior inherit from Character? What contracts might break?"

### 4. Interface Segregation Principle (ISP)
**Don't Force Unnecessary Methods:**
```cpp
// Bad: Not all items are equippable
class Item {
    virtual void use() = 0;
    virtual void equip() = 0;  // Potions can't be equipped!
};

// Good: Separate interfaces
class Usable {
    virtual void use() = 0;
};
class Equippable {
    virtual void equip() = 0;
};
class Potion : public Item, public Usable { /* use only */ };
class Sword : public Item, public Equippable { /* equip only */ };
```

### 5. Dependency Inversion Principle (DIP)
**Depend on Abstractions:**
```cpp
// Bad: Character depends on specific save format
class Character {
    void save() {
        BinaryFile file("save.dat");  // Tied to binary files!
        // ...
    }
};

// Good: Character depends on abstraction
class SaveStrategy {
    virtual void save(Character& c) = 0;
};
class Character {
    void save(SaveStrategy& strategy) {
        strategy.save(*this);  // Any save format works
    }
};
```

---

## Week 15: Integration and Code Review
### "From Student Code to Portfolio Code"

**Professional Code Review Checklist:**
- [ ] Meaningful variable/function names
- [ ] Consistent formatting
- [ ] No code duplication (DRY)
- [ ] Error handling present
- [ ] Comments explain "why" not "what"
- [ ] SOLID principles applied where appropriate

**AI-Assisted Refactoring:**
```
"Review this function for SOLID violations:
[paste code]
Suggest refactoring that maintains functionality
while improving design. Explain each change."
```

---

## Assessment Rubric: Engineering Practices

### C Level: Basic Agile Understanding
- Writes user stories for features
- Completes work in sprint timeframes
- Participates in retrospectives
- Basic OOP implementation

### B Level: Applying Principles
- User stories include acceptance criteria
- Code shows clear encapsulation
- Attempts to follow SOLID principles
- Can explain design choices

### A Level: Thoughtful Engineering
- Comprehensive sprint planning
- Consistent SOLID application
- Refactors based on principles
- Teaches concepts to peers

### Badge Level: Professional Practice
- Leads agile ceremonies
- Architecture follows all SOLID principles
- Can defend design tradeoffs
- Code review shows deep understanding
- Portfolio-ready documentation

---

## Capstone Integration

Badge candidates must demonstrate:
1. **Agile Artifacts**: User stories, sprint plans, retrospectives
2. **SOLID Design**: Clear principle application with justification
3. **Evolution**: Show code progression from procedural to OOP to SOLID
4. **Teaching**: Explain principles to others in documentation
5. **AI Integration**: Use AI to explore advanced patterns while maintaining understanding

---

## Reflection Questions for Portfolio

1. How did Agile practices change your development approach?
2. Which SOLID principle was hardest to understand? Why?
3. Show a before/after refactoring using SOLID principles
4. How did AI help you understand these concepts?
5. What engineering practices will you continue using?