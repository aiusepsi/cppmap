cppmap
======

An experiment in using type-inference and templates. Implements a map() function which takes an iterable object (anything with a .begin() method) and any unary callable (e.g. function pointer or functor) and returns a list comprising the items of the iterable object transformed by the unary callable.

My only annoyance is that I can't get the type deduction to work properly when passing an initialiser list directly without assigning it to a variable first.
