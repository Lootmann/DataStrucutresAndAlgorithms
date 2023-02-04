import pytest

from src import myjwt
from src.myjwt import Jwt


def test_header_base64encode():
    header = {"alg": "HS256", "typ": "JWT"}
    want = b"eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9"
    got = myjwt.Jwt.base64encode(header)

    assert want == got


def test_payload_base64encode():
    test_data = [
        (
            {"sub": "1234567890", "name": "John Doe", "iat": 1516239022},
            b"eyJzdWIiOiIxMjM0NTY3ODkwIiwibmFtZSI6IkpvaG4gRG9lIiwiaWF0IjoxNTE2MjM5MDIyfQ",
        ),
        (
            {"sub": "98765432", "name": "Hoge Hage Hige", "iat": 9673284},
            b"eyJzdWIiOiI5ODc2NTQzMiIsIm5hbWUiOiJIb2dlIEhhZ2UgSGlnZSIsImlhdCI6OTY3MzI4NH0",
        ),
        (
            {"sub": "1234567890", "name": "John Doe", "admin": True},
            b"eyJzdWIiOiIxMjM0NTY3ODkwIiwibmFtZSI6IkpvaG4gRG9lIiwiYWRtaW4iOnRydWV9",
        ),
    ]

    for payload, want in test_data:
        got = myjwt.Jwt.base64encode(payload)
        assert want == got


def test_signature_1():
    header = {"alg": "HS256", "typ": "JWT"}
    payload = {"sub": "1234567890", "name": "John Doe", "admin": True}
    secret_key = "hoge"
    algorithm = "sha256"

    msg = Jwt.base64encode(header) + b"." + Jwt.base64encode(payload)
    want = b"B5TC_xWs0gnfHH5ZzJYxkRwPzWF5HReVTe4By2h-sGg"
    got = Jwt.signatured(secret_key, msg, algorithm)

    assert want == got


def test_signature_2():
    header = {"alg": "HS256", "typ": "JWT"}
    payload = {
        "iat": 1653199095,
        "jti": "da5dd8a6-15c5-4197-9f6b-cc0f6051dcf2",
        "type": "access",
        "sub": "U0000000120",
        "nbf": 1653199095,
        "exp": 1653199995,
    }
    secret_key = "ads6fhkasdf987@0apd98fadalkjp9a3whf"
    algorithm = "sha256"

    msg = Jwt.base64encode(header) + b"." + Jwt.base64encode(payload)
    want = b"j6XpoNCB7qfE8weCJnfD7snGRntQYbAkhjhk9Nud_4Q"
    got = Jwt.signatured(secret_key, msg, algorithm)

    assert want == got


def test_jwt_encode():
    header = {"alg": "HS256", "typ": "JWT"}
    payload = {"loggedInAs": "admin", "iat": 1422779638}
    secret_key = "secretkey"
    algorithm = "sha256"

    got = Jwt.encode(header, payload, secret_key, algorithm)
    want = "eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJsb2dnZWRJbkFzIjoiYWRtaW4iLCJpYXQiOjE0MjI3Nzk2Mzh9.gzSraSYS8EXBxLN_oWnFSRgCzcmJmMjLiuyu5CSpyHI"

    assert got == want


def test_jwt_encode_with_sha384():
    header = {"alg": "HS384", "typ": "JWT"}
    payload = {"name": "admin", "iat": 1422779638, "some": "here is payload"}
    secret_key = "secretkey"
    algorithm = "sha384"

    got = Jwt.encode(header, payload, secret_key, algorithm)
    want = "eyJhbGciOiJIUzM4NCIsInR5cCI6IkpXVCJ9.eyJuYW1lIjoiYWRtaW4iLCJpYXQiOjE0MjI3Nzk2MzgsInNvbWUiOiJoZXJlIGlzIHBheWxvYWQifQ.c8JwegkSbBuDG9gxllJTJ-d787L9acNSjDDgs7TcYdiqHrz4TWJyIOObLbKseUUz"

    assert got == want


def test_jwt_encode_with_sha512():
    header = {"alg": "HS512", "typ": "JWT"}
    payload = {"loggedInAs": "admin", "iat": 1422779638, "usb": "AAC12230"}
    secret_key = "SuperSecureSecret"
    algorithm = "sha512"

    got = Jwt.encode(header, payload, secret_key, algorithm)
    want = "eyJhbGciOiJIUzUxMiIsInR5cCI6IkpXVCJ9.eyJsb2dnZWRJbkFzIjoiYWRtaW4iLCJpYXQiOjE0MjI3Nzk2MzgsInVzYiI6IkFBQzEyMjMwIn0.OM9CyKnyWIBOhUAA-YbV1bOaq7o3ZUbi5dk4PJvx35tZodV08uSkpqP8XkbhHsYcsN7f42qF7hV_4UiFwPJWYg"

    assert got == want


def test_jwt_encode_with_wrong_algorithm():
    algorithm = "hogege"

    with pytest.raises(ValueError):
        Jwt.encode({}, {}, ":^)", algorithm)
