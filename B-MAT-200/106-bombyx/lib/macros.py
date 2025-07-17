from math import pi

def deg_to_rad(radians: float) -> float:
    return radians * 180 / pi

def check_type(variable: object, target_type: object):
    try:
        type_conv = type(target_type(variable)).__name__
        type_var = target_type.__name__
        if type_conv != type_var:
            raise TypeError
        return True
    except:
        return False

class ErrorCodes:
    EXIT_SUCCESS: int = 0
    EXIT_FAILURE: int = 1
    EXIT_FAILURE_84: int = 84