from Transport import Transport
import random


class Plane(Transport):
    def __init__(self, params=None):
        super().__init__(params)
        if params is None:
            self.max_distance = 0
            self.capacity = 0
        else:
            self.max_distance = int(params[2])
            self.capacity = int(params[3])

    def generate(self):
        super().generate()
        self.max_distance = random.randint(950, 2000)
        self.capacity = random.randint(1, 15)
        return self

    def measure_time(self) -> float:
        if self.distance > self.max_distance:
            return 1e100 + self.distance
        return super().measure_time()

    def __str__(self):
        return f"Plane {super().__str__()} {self.max_distance} {self.capacity}"
