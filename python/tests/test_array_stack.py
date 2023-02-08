import pytest

from src.array_stack import ArrayStack
from src.custom_exception import InvalidStackOperation


class TestArrayStackWithoutArgs:
    @pytest.fixture(autouse=True)
    def initial(self):
        self.stack = ArrayStack()

    def test_init(self):
        assert len(self.stack) == 0

        for i in range(len(self.stack)):
            assert self.stack[i] == 0

    def test_fill(self):
        for i in range(len(self.stack)):
            assert self.stack[i] == 0

        self.stack.fill(99)

        for i in range(len(self.stack)):
            assert self.stack[i] == 99
            assert self.stack[i] != 0

    def test_capacity(self):
        assert self.stack.cap() == 20


class TestArrayStackOperation:
    @pytest.fixture(autouse=True)
    def initial(self):
        self.stack = ArrayStack()

    def test_push(self):
        assert len(self.stack) == 0

        self.stack.push(1)
        assert len(self.stack) == 1

        self.stack.push(1)
        assert len(self.stack) == 2

        self.stack.push(1)
        assert len(self.stack) == 3

    def test_resize(self):
        for i in range(21):
            self.stack.push(i)

        assert self.stack.cap() == 40

    def test_push_many(self):
        for i in range(1000):
            self.stack.push(i)

        assert len(self.stack) == 1000
        assert self.stack.cap() == 1280

        for i in range(1000):
            assert len(self.stack) == 1000 - i
            assert self.stack.top() == 1000 - i - 1
            assert self.stack.pop() == 1000 - i - 1

        assert self.stack.is_empty() is True


class TestArrayStackRaisesException:
    @pytest.fixture(autouse=True)
    def initial(self):
        self.stack = ArrayStack()

    def test_init_invalid_size(self):
        with pytest.raises(InvalidStackOperation):
            ArrayStack(-1)

    def test_access(self):
        with pytest.raises(InvalidStackOperation):
            self.stack[2]

    def test_pop(self):
        with pytest.raises(InvalidStackOperation):
            self.stack.pop()

    def test_push(self):
        for i in range(10):
            self.stack.push(i)

        for i in range(10):
            self.stack.pop()

        with pytest.raises(InvalidStackOperation):
            self.stack.pop()

    def test_top(self):
        with pytest.raises(InvalidStackOperation):
            self.stack.top()
