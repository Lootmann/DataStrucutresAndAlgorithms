"""array_stack.py
This is python 🐍
but I want to impl Fixed Array.
why 🤔
"""
from src.custom_exception import InvalidStackOperation


class ArrayStack:
    def __init__(self, size=20) -> None:
        if size < 0:
            raise InvalidStackOperation(f"Size: {size} must be Positive")

        self._size = size
        self._array = [0] * self._size

        self._idx = -1

    def push(self, num) -> None:
        if self._idx >= self._size - 1:
            self._resize()

        self._idx += 1
        self._array[self._idx] = num

    def pop(self) -> int:
        if self.is_empty():
            raise InvalidStackOperation("Stack Is Empty")

        popped = self._array[self._idx]
        self._idx -= 1
        return popped

    def top(self) -> int:
        if self.is_empty():
            raise InvalidStackOperation("Stack Is Empty")
        return self._array[self._idx]

    def fill(self, num: int) -> None:
        for i in range(self._size):
            self._array[i] = num

    def is_empty(self) -> bool:
        return self._idx == -1

    def _resize(self) -> None:
        new_size = self._size * 2
        new_array = [0] * new_size
        for i in range(self._size):
            new_array[i] = self._array[i]

        self._size = new_size
        self._array = new_array

    def __getitem__(self, key: int) -> int:
        if not 0 <= key < self._idx + 1:
            raise InvalidStackOperation("Outbound")
        return self._array[key]

    def cap(self) -> int:
        return self._size

    def __len__(self) -> int:
        return self._idx + 1
