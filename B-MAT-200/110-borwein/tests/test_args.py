from unittest.mock import patch
from lib.macros import ErrorCodes
from main import main
import unittest
import sys
import io

PROG_NAME = ["./110borwein"]

def get_usage() -> str:
    try:
        file = open("usage.txt", "r")
        str = file.read()
        file.close()
        return str
    except:
        return ""

class TestArguments_InitValid(unittest.TestCase):
    def test_classic(self):
        arguments = [PROG_NAME] + ["0"]

        with self.assertRaises(SystemExit) as cm:
            main(arguments)
            if hasattr(cm, "exception") == True:
                self.fail("Exception raised!")
        self.assertEqual(cm.exception.code, ErrorCodes.EXIT_SUCCESS)

    @patch('sys.stdout', new_callable=io.StringIO)
    def test_help_flag_1(self, mock_out):
        expected_output = get_usage()
        arguments = [PROG_NAME] + ["-h"]

        with self.assertRaises(SystemExit) as cm:
            main(arguments)
            if hasattr(cm, "exception") == True:
                self.fail("Exception raised!")
        self.assertEqual(cm.exception.code, ErrorCodes.EXIT_SUCCESS)
        self.assertEqual(mock_out.getvalue(), expected_output)

    @patch('sys.stdout', new_callable=io.StringIO)
    def test_help_flag_2(self, mock_out):
        expected_output = get_usage()
        arguments = [PROG_NAME] + ["--help"]

        with self.assertRaises(SystemExit) as cm:
            main(arguments)
            if hasattr(cm, "exception") == True:
                self.fail("Exception raised!")
        self.assertEqual(cm.exception.code, ErrorCodes.EXIT_SUCCESS)
        self.assertEqual(mock_out.getvalue(), expected_output)

class TestArguments_InitInvalid(unittest.TestCase):
    @patch('sys.stderr', new_callable=io.StringIO)
    def test_not_enough_values(self, mock_out):
        arguments = [PROG_NAME]

        with self.assertRaises(SystemExit) as cm:
            main(arguments)
            if hasattr(cm, "exception") != True:
                self.fail("Exception not raised!")
        self.assertEqual(cm.exception.code, ErrorCodes.EXIT_FAILURE_84)

    @patch('sys.stderr', new_callable=io.StringIO)
    def test_too_much_values(self, mock_out):
        arguments = [PROG_NAME] + ["0", "1"]

        with self.assertRaises(SystemExit) as cm:
            main(arguments)
            if hasattr(cm, "exception") != True:
                self.fail("Exception not raised!")
        self.assertEqual(cm.exception.code, ErrorCodes.EXIT_FAILURE_84)

    @patch('sys.stderr', new_callable=io.StringIO)
    def test_bad_number(self, mock_out):
        arguments = [PROG_NAME] + ["-1"]

        with self.assertRaises(SystemExit) as cm:
            main(arguments)
            if hasattr(cm, "exception") != True:
                self.fail("Exception not raised!")
        self.assertEqual(cm.exception.code, ErrorCodes.EXIT_FAILURE_84)

    @patch('sys.stdout', new_callable=io.StringIO)
    def test_help_flag_1(self, mock_out):
        expected_output = get_usage()
        arguments = [PROG_NAME] + ["0", "-h"]

        with self.assertRaises(SystemExit) as cm:
            main(arguments)
            if hasattr(cm, "exception") == True:
                self.fail("Exception raised!")
            self.assertEqual(cm.exception.code, ErrorCodes.EXIT_SUCCESS)
        self.assertEqual(mock_out.getvalue(), expected_output)

    @patch('sys.stdout', new_callable=io.StringIO)
    def test_help_flag_2(self, mock_out):
        expected_output = get_usage()
        arguments = [PROG_NAME] + ["0", "--help"]

        with self.assertRaises(SystemExit) as cm:
            main(arguments)
            if hasattr(cm, "exception") == True:
                self.fail("Exception raised!")
        self.assertEqual(cm.exception.code, ErrorCodes.EXIT_SUCCESS)
        self.assertEqual(mock_out.getvalue(), expected_output)

class TestArguments_InitCrash(unittest.TestCase):
    def test_empty_args(self):
        arguments = []

        with self.assertRaises(SystemExit) as cm:
            main(arguments)
            if hasattr(cm, "exception") != True:
                self.fail("Exception not raised!")
        self.assertEqual(cm.exception.code, ErrorCodes.EXIT_FAILURE_84)
