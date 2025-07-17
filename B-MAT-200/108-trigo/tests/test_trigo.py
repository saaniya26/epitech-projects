from unittest.mock import patch
from lib.macros import ErrorCodes
from main import main
import unittest
import sys
import io

PROG_NAME = ["./108trigo"]

def get_test_ref(test_class: str) -> str:
    try:
        file = open(f"tests/t_files/test_{test_class}.txt", "r")
        str = file.read()
        file.close()
        return str
    except:
        return ""

class TestPoly_Calculate(unittest.TestCase):
    @patch('sys.stdout', new_callable=io.StringIO)
    def test_classic_cos_1(self, mock_out):
        arguments = [PROG_NAME] + ["COS", "4", "5", "9", "3", "3", "5", "0", "1", "9"]

        with self.assertRaises(SystemExit) as cm:
            main(arguments)
            if hasattr(cm, "exception") != True:
                self.fail("Exception not raised!")
        self.assertEqual(cm.exception.code, ErrorCodes.EXIT_SUCCESS)
        self.assertEqual(mock_out.getvalue(), get_test_ref("classic_cos_1"))

    @patch('sys.stdout', new_callable=io.StringIO)
    def test_classic_exp_1(self, mock_out):
        arguments = [PROG_NAME] + ["EXP", "1", "2", "3", "4"]

        with self.assertRaises(SystemExit) as cm:
            main(arguments)
            if hasattr(cm, "exception") != True:
                self.fail("Exception not raised!")
        self.assertEqual(cm.exception.code, ErrorCodes.EXIT_SUCCESS)
        self.assertEqual(mock_out.getvalue(), get_test_ref("classic_exp_1"))

    @patch('sys.stdout', new_callable=io.StringIO)
    def test_classic_sinh(self, mock_out):
        arguments = [PROG_NAME] + ["SINH", "1", "0", "2", "0"]

        with self.assertRaises(SystemExit) as cm:
            main(arguments)
            if hasattr(cm, "exception") != True:
                self.fail("Exception not raised!")
        self.assertEqual(cm.exception.code, ErrorCodes.EXIT_SUCCESS)
        self.assertEqual(mock_out.getvalue(), get_test_ref("classic_sinh_1"))