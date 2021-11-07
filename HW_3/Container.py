from Plane import Plane
from Ship import Ship
from Train import Train
import random

str_to_transport = {'Plane': Plane, 'Ship': Ship, 'Train': Train}


class Container:
    def __init__(self):
        self.size = 0
        self.transports = []

    def generate(self, size):
        self.size = size
        transport_types = [Plane, Ship, Train]
        for i in range(self.size):
            self.transports.append(random.choice(transport_types)().generate())

    def read(self, path):
        with open(path, 'r') as fin:
            self.size = int(fin.readline())
            for i in range(self.size):
                line = fin.readline().split()
                self.transports.append(str_to_transport[line[0]](line[1:]))

    def write(self, path):
        with open(path, 'w') as fout:
            fout.write(str(self.size) + '\n')

            for i in range(self.size):
                fout.write(str(self.transports[i]) + '\n')

    def sort(self):
        gap = self.size // 2

        while gap > 0:
            for i in range(gap, self.size):
                tmp = self.transports[i]
                j = i
                while j >= gap and self.transports[j - gap].measure_time() < tmp.measure_time():
                    self.transports[j] = self.transports[j - gap]
                    j -= gap

                self.transports[j] = tmp
            gap //= 2
