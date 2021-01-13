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
