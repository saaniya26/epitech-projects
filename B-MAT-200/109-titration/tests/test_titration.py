from unittest.mock import patch
from lib.macros import ErrorCodes
from main import main
import unittest
import sys
import io

PROG_NAME = ["./109titration"]

def get_test_ref(test_class: str) -> str:
    try:
        file = open(f"tests/t_files/test_{test_class}_expected.txt", "r")
        str = file.read()
        file.close()
        return str
    except:
        return ""

class TestTitration_Calculate(unittest.TestCase):
    @patch('sys.stdout', new_callable=io.StringIO)
    def test_classic(self, mock_out):
        arguments = [PROG_NAME] + ["tests/t_files/test_classic.csv"]

        self.skipTest("Calculator not implemented") ## Remove this when calculator is implemented
        with self.assertRaises(SystemExit) as cm:
            main(arguments)
            if hasattr(cm, "exception") != True:
                self.fail("Exception not raised!")
        self.assertEqual(cm.exception.code, ErrorCodes.EXIT_SUCCESS)
        self.assertEqual(mock_out.getvalue(), get_test_ref("classic"))
