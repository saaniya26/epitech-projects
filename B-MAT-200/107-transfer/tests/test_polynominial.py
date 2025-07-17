from unittest.mock import patch
from lib.macros import ErrorCodes
from main import main
import unittest
import sys
import io

def get_test_ref(test_class: str) -> str:
    try:
        file = open(f"tests/t_poly_eo/eo_{test_class}.txt", "r")
        str = file.read()
        file.close()
        return str
    except:
        return ""

class TestPoly_Calculate(unittest.TestCase):
    @patch('sys.stdout', new_callable=io.StringIO)
    def test_classic(self, mock_out):
        arguments = ["0*1*2*3*4", "1"]

        with self.assertRaises(SystemExit) as cm:
            main(arguments)
            if hasattr(cm, "exception") != True:
                self.fail("Exception not raised!")
        self.assertEqual(cm.exception.code, ErrorCodes.EXIT_SUCCESS)
        self.assertEqual(mock_out.getvalue(), get_test_ref("classic"))
