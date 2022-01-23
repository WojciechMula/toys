import time

class Status:
    def __init__(self):
        self.last_update = 0.0
        self.last_len = 0

    def __call__(self, msg, force=False):
        now = time.time()
        if not force and (now - self.last_update < 0.5):
            return

        self.last_update = now
        self.last_len = len(msg)
        print(f"{msg}\r", end='')

    def clear(self):
        print((self.last_len * ' ') + "\r", end='')
        self.last_update = 0.0
        self.last_len = 0

