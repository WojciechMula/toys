================================================================================
            You cannot easily mock context managers in Python
================================================================================

The builtin ``unittest.mock.Mock`` class has a nice feature which allows to
easily generate a mock based on any class: ``Mock(spec=class_name)``.

Unfortunately, such mocked object does not expose magic methods ``__enter__``
and  ``__exit__``, which are used to implement **context managers**.

Here is a sample code::

    from unittest.mock import Mock

    class ContextManager:
        def foo(self):
            pass

        def __enter__(self, *args):
            return self

        def __exit__(self, *args):
            pass

    print("Methods of 'ContextManager':")
    print(dir(ContextManager()))

    ctx = ContextManager()

    with ctx:
        pass

    mock = Mock(spec=ContextManager)
    print("Methods of 'Mock(spec=ContextManager)':")
    print(dir(mock))

    for magic_method in ['__enter__', '__exit__']:
        method_in_dir = magic_method in dir(mock)
        try:
            getattr(mock, '__enter__')
            method_accessible = True
        except AttributeError:
            method_accessible = False

        print(f"{magic_method} in dir(m)? {method_in_dir}")
        print(f"{magic_method} accessible via getattr? {method_accessible}")

The output from Python 3.9 is::

    Methods of 'ContextManager':
    ['__class__', '__delattr__', '__dict__', '__dir__', '__doc__', '__enter__',
    '__eq__', '__exit__', '__format__', '__ge__', '__getattribute__', '__gt__',
    '__hash__', '__init__', '__init_subclass__', '__le__', '__lt__',
    '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__',
    '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__',
    '__weakref__', 'foo']
    Methods of 'Mock(spec=ContextManager)':
    ['__class__', '__delattr__', '__dict__', '__dir__', '__doc__', '__enter__',
    '__eq__', '__exit__', '__format__', '__ge__', '__getattribute__', '__gt__',
    '__hash__', '__init__', '__init_subclass__', '__le__', '__lt__',
    '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__',
    '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__',
    '__weakref__', 'assert_any_call', 'assert_called', 'assert_called_once',
    'assert_called_once_with', 'assert_called_with', 'assert_has_calls',
    'assert_not_called', 'attach_mock', 'call_args', 'call_args_list',
    'call_count', 'called', 'configure_mock', 'foo', 'method_calls',
    'mock_add_spec', 'mock_calls', 'reset_mock', 'return_value', 'side_effect']
    __enter__ in dir(m)? True
    __enter__ accessible via getattr? False
    __exit__ in dir(m)? True
    __exit__ accessible via getattr? False

As we see from ``dir()`` output, the mocked object do have method ``foo`` from
``ContextManager`` class. Also the magic methods are visible, but they remain
inaccessible via standard ``getattr`` function. This makes the mocked object
unusable in ``with`` statements, an interpreter reports following error::

    >>> with mock: pass
    ... 
    Traceback (most recent call last):
      File "<stdin>", line 1, in <module>
    AttributeError: __enter__

Fortunately, it's possible to redefine the magic methods::

    >>> mock.__enter__ = lambda self, *args: self
    >>> 
    >>> mock.__exit__ = lambda self, *args: None
    >>> 
    >>> with mock: pass
    ... 
    >>> 

In older versions of Python it might not work.
