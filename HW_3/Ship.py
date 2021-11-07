from Transport import Transport
import enum
import random


class ShipType(enum.Enum):
    LINER = 1
    TOW = 2
    TANKER = 3


str_to_type = {"LINER": ShipType.LINER, "TOW": ShipType.TOW, "TANKER": ShipType.TANKER}


class Ship(Transport):
    def __init__(self, params=None):
        super().__init__(params)
        if params is None:
            self.type = ShipType.LINER
            self.displacement = 0
        else:
            self.displacement = int(params[2])
            self.type = str_to_type[params[3]]

    def generate(self):
        super().generate()
        self.type = ShipType(random.randint(1, 3))
        self.displacement = random.randint(100, 1000)
        return self

    def __str__(self):
        return f"Ship {super().__str__()} {self.displacement} {self.type.name}"
