import random


class Transport:
    def __init__(self, params=None):
        if params is None:
            self.distance = 0
            self.velocity = 0
        else:
            self.velocity = int(params[0])
            self.distance = float(params[1])

    def measure_time(self) -> float:
        if not self.velocity:
            return 1e100 + self.distance
        return self.distance / self.velocity

    def generate(self):
        self.distance = random.randint(1, 1000)
        self.velocity = random.randint(1, 400)
        return self

    def __str__(self):
        return f"{round(self.measure_time(), 3)} {self.velocity} {self.distance}"
