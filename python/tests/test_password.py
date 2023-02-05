from src.passwords import get_password_hash, verify_password


def test_password_hash():
    plain = "hoge"
    hashed = get_password_hash(password=plain)
    print(hashed)


def test_verify_password():
    plain = "hello_world"
    hashed = get_password_hash(plain)

    assert verify_password(plain=plain, hashed=hashed) is True


def test_not_verify_password():
    plain = "hello_world"
    hashed = get_password_hash(plain)

    assert verify_password(plain="hollow_world", hashed=hashed) is False
