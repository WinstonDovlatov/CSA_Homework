from Transport import Transport
import random


class Train(Transport):
    def __init__(self, params=None):
        super().__init__(params)
        if params is None:
            self.cars_number = 0
        else:
            self.cars_number = int(params[2])

    def generate(self):
        super().generate()
        self.cars_number = random.randint(1, 100)
        return self

    def __str__(self):
        return f"Train {super().__str__()} {self.cars_number}"
