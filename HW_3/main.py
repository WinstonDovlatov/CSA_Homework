import sys
import time
from Container import Container
from Errors import InvalidArgsError


def get_container():
    if len(sys.argv) != 5:
        raise InvalidArgsError("Excepted 4 args")

    result = Container()
    if sys.argv[1] == '-f':
        result.read(sys.argv[2])
    elif sys.argv[1] == '-n':
        if not sys.argv[2].isdigit():
            raise InvalidArgsError("After '-n'  you must enter positive number")
        size = int(sys.argv[2])
        if size < 0 or size > 10000:
            raise InvalidArgsError("Size must be in range [0, 10000]")
        result.generate(size)
    else:
        raise InvalidArgsError(f"Excepted flag '-n' or '-f', got '{sys.argv[1]}'")

    return result


if __name__ == '__main__':
    try:
        t_start = time.time()

        print("reading...", end='')
        container = get_container()
        print('done\nwriting...', end='')
        container.write(sys.argv[3])
        print('done\nsorting...', end='')

        container.sort()
        print('done\nwriting...', end='')

        container.write(sys.argv[4])
        print('done')

        t_end = time.time()
        print(f"Passed {round((t_end - t_start) * 1000)}ms")

    except InvalidArgsError as err:
        print(f"Invalid args. Excepted '-f path_in path_out1 path_out2' or '-n size path_out1 path_out2'. {err}")
    except FileExistsError or FileNotFoundError as err:
        print(f"File error. {err}")
    except() as err:
        print(f"Error. {err}")
