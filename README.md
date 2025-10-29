# C++ Module 06

# Scalar Type conversion & Casting

This module explores *type casting* and *scalar type conversions* in C++.
It focuses on understanding the differences between implicit and explicit casts, and how to handle conversions between fundamental data types (`char`, `int`, `float`, `double`).

The main project — ex00, **ScalarConverter** — implements a static class capable of detecting a literal’s type from its string representation and converting it to all four scalar types, handling edge cases like overflow, non-displayable characters, and special pseudo-literals (`nan`, `+inf`, `-inf`, `nanf`, `+inff`, `-inff`).

**Key concepts:**
- Static classes and non-instantiable design
- `static_cast`, `reinterpret_cast`, and `dynamic_cast`
- Literal parsing and type detection
- Handling pseudo-literals (`nan`, `+inf`, `-inf`, `nanf`, `+inff`, `-inff`)
- Safe conversions and error handling

----
✅ Check out [C++ Module 07](https://github.com/ricvrdv/cpp-07) - function and class templates

⏪️ Go back to [C++ Module 05](https://github.com/ricvrdv/cpp-05) - exception handling
