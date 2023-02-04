"""myjwt.py
My JWT Implementation

pyjwt is like
>>> jwt.encode({"some": "payload"}, "secret", algorithm="HS256")

I think this is a class method(or static method).

* header
{
  "alg": "HS256",
  "typ": "JWT"
}
>>> eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9

* payload
{
  "sub": "1234567890",
  "name": "John Doe",
  "iat": 1516239022
}
>>> eyJzdWIiOiIxMjM0NTY3ODkwIiwibmFtZSI6IkpvaG4gRG9lIiwiaWF0IjoxNTE2MjM5MDIyfQ

* signature
HMACSHA256(
  base64UrlEncode(header) + "." +
  base64UrlEncode(payload),
  your-256-bit-secret
)
"""

import base64
import json


class Jwt:
    @classmethod
    def encode(cls, header: dict, payload, dict, secret_key: str, algorithm: str):
        pass

    @classmethod
    def base64encode(cls, d: dict) -> bytes:
        # separators do trailing white space
        json_string = json.dumps(d, separators=(",", ":"))

        data = json_string.encode("utf-8")
        encoded = base64.b64encode(data)
        return encoded
