# import jwt
#
#
# def test():
#     encoded_jwt = jwt.encode({"some": "payload"}, "secret", algorithm="HS256")
#     print(encoded_jwt)

from src import myjwt


def test_header_base64encode():
    header = {"alg": "HS256", "typ": "JWT"}
    want = b"eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9"
    got = myjwt.Jwt.base64encode(header)

    print(got)

    assert want == got
