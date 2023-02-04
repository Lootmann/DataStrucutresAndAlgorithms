import base64
import hashlib
import hmac
import json


class Jwt:
    @classmethod
    def encode(cls, header: dict, payload: dict, secret_key: str, algorithm: str) -> str:
        if not Jwt.validation_header(header, algorithm):
            raise ValueError("ValidationError: header")

        encoded_header = cls.base64encode(header)
        encoded_payload = cls.base64encode(payload)

        signature = cls.signatured(
            secret_key,
            encoded_header + b"." + encoded_payload,
            algorithm,
        )

        jwt = encoded_header + b"." + encoded_payload + b"." + signature

        return jwt.decode()

    @classmethod
    def base64encode(cls, d: dict) -> bytes:
        # separators do trailing white space
        json_string = json.dumps(d, separators=(",", ":"))

        data = json_string.encode("utf-8")
        # NOTE: not use base64encode, you must use urlsafe b64encode
        #       and encoded string has no '=' padding
        encoded = base64.urlsafe_b64encode(data).replace(b"=", b"")

        return encoded

    @classmethod
    def signatured(cls, secret_key: str, msg: bytes, algorithm: str) -> bytes:
        alg = Jwt.validation_alg(algorithm)

        if not alg:
            raise ValueError("Unknown algorithm")

        t = hmac.new(str.encode(secret_key), msg, alg)
        return base64.urlsafe_b64encode(t.digest()).replace(b"=", b"")

    @classmethod
    def validation_header(cls, header: dict, algorithm: str) -> bool:
        can_use_algs = {
            "HS256": "sha256",
            "HS384": "sha384",
            "HS512": "sha512",
        }

        if "alg" not in header:
            return False

        if header["alg"] not in can_use_algs:
            return False

        if can_use_algs[header["alg"]] != algorithm:
            return False

        return True

    @classmethod
    def validation_alg(cls, algorithm: str):
        mp = {
            "sha256": hashlib.sha256,
            "sha384": hashlib.sha384,
            "sha512": hashlib.sha512,
        }
        return mp.get(algorithm, None)
