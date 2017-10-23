## Subclass

A class built using inheritance

## Subtype

It is a subclass, but subclasses are not necessarily subtypes.
It's a subtype if it provides all the operations of the parent class **and** satisfies all properties associated with the parent class.

## Pre and Post conditions

**Precondition**: states what must be true before a method can be executed.

**Postcondition**: states what is guaranteed to be true after the method is executed.

**e.g.**

```cpp
// precond: Stack s is not full
// postcond: item is inserted at top of s,
// 	     and s is unchanged otherwise
public void push(itemtype item);
```

## Storage using subclasses

1. Minimum space allocation
1. Maximum space allocation
1. Dynamic memory allocation


