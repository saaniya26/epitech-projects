from unittest.mock import patch
from lib.macros import ErrorCodes
from main import main
import unittest
import sys
import io

PROG_NAME = ["./108trigo"]

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
        arguments = [PROG_NAME] + ["EXP", "1", "2", "3", "4"]

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
    def test_missing_operand(self, mock_out):
        arguments = [PROG_NAME]

        with self.assertRaises(SystemExit) as cm:
            main(arguments)
            if hasattr(cm, "exception") != True:
                self.fail("Exception not raised!")
        self.assertEqual(cm.exception.code, ErrorCodes.EXIT_FAILURE_84)

    @patch('sys.stderr', new_callable=io.StringIO)
    def test_invalid_operand(self, mock_out):
        arguments = [PROG_NAME] + ["EXPe", "1", "2", "3", "4"]

        with self.assertRaises(SystemExit) as cm:
            main(arguments)
            if hasattr(cm, "exception") != True:
                self.fail("Exception not raised!")
        self.assertEqual(cm.exception.code, ErrorCodes.EXIT_FAILURE_84)

    @patch('sys.stderr', new_callable=io.StringIO)
    def test_missing_number(self, mock_out):
        arguments = [PROG_NAME] + ["EXP"]

        with self.assertRaises(SystemExit) as cm:
            main(arguments)
            if hasattr(cm, "exception") != True:
                self.fail("Exception not raised!")
        self.assertEqual(cm.exception.code, ErrorCodes.EXIT_FAILURE_84)

    @patch('sys.stderr', new_callable=io.StringIO)
    def test_not_enough_values(self, mock_out):
        arguments = [PROG_NAME] + ["EXP", "1", "2", "3"]

        with self.assertRaises(SystemExit) as cm:
            main(arguments)
            if hasattr(cm, "exception") != True:
                self.fail("Exception not raised!")
        self.assertEqual(cm.exception.code, ErrorCodes.EXIT_FAILURE_84)

    @patch('sys.stderr', new_callable=io.StringIO)
    def test_letters_in_values_1(self, mock_out):
        arguments = [PROG_NAME] + ["EXP", "1aze", "2", "3", "4"]

        with self.assertRaises(SystemExit) as cm:
            main(arguments)
            if hasattr(cm, "exception") != True:
                self.fail("Exception not raised!")
        self.assertEqual(cm.exception.code, ErrorCodes.EXIT_FAILURE_84)

    @patch('sys.stderr', new_callable=io.StringIO)
    def test_letters_in_values_2(self, mock_out):
        arguments = [PROG_NAME] + ["EXP", "1", "2aze", "3", "4"]

        with self.assertRaises(SystemExit) as cm:
            main(arguments)
            if hasattr(cm, "exception") != True:
                self.fail("Exception not raised!")
        self.assertEqual(cm.exception.code, ErrorCodes.EXIT_FAILURE_84)

    @patch('sys.stderr', new_callable=io.StringIO)
    def test_letters_in_values_3(self, mock_out):
        arguments = [PROG_NAME] + ["EXP", "1", "2", "3aze", "4"]

        with self.assertRaises(SystemExit) as cm:
            main(arguments)
            if hasattr(cm, "exception") != True:
                self.fail("Exception not raised!")
        self.assertEqual(cm.exception.code, ErrorCodes.EXIT_FAILURE_84)

    @patch('sys.stderr', new_callable=io.StringIO)
    def test_letters_in_values_4(self, mock_out):
        arguments = [PROG_NAME] + ["EXP", "1", "2", "3", "4aze"]

        with self.assertRaises(SystemExit) as cm:
            main(arguments)
            if hasattr(cm, "exception") != True:
                self.fail("Exception not raised!")
        self.assertEqual(cm.exception.code, ErrorCodes.EXIT_FAILURE_84)

    @patch('sys.stderr', new_callable=io.StringIO)
    def test_empty_args_1(self, mock_out):
        arguments = [PROG_NAME] + ["EXP", "", "2", "3", "4"]

        with self.assertRaises(SystemExit) as cm:
            main(arguments)
            if hasattr(cm, "exception") != True:
                self.fail("Exception not raised!")
        self.assertEqual(cm.exception.code, ErrorCodes.EXIT_FAILURE_84)

    @patch('sys.stderr', new_callable=io.StringIO)
    def test_empty_args_2(self, mock_out):
        arguments = [PROG_NAME] + ["EXP", "1", "", "3", "4"]

        with self.assertRaises(SystemExit) as cm:
            main(arguments)
            if hasattr(cm, "exception") != True:
                self.fail("Exception not raised!")
        self.assertEqual(cm.exception.code, ErrorCodes.EXIT_FAILURE_84)

    @patch('sys.stderr', new_callable=io.StringIO)
    def test_empty_args_3(self, mock_out):
        arguments = [PROG_NAME] + ["EXP", "1", "2", "", "4"]

        with self.assertRaises(SystemExit) as cm:
            main(arguments)
            if hasattr(cm, "exception") != True:
                self.fail("Exception not raised!")
        self.assertEqual(cm.exception.code, ErrorCodes.EXIT_FAILURE_84)

    @patch('sys.stderr', new_callable=io.StringIO)
    def test_empty_args_4(self, mock_out):
        arguments = [PROG_NAME] + ["EXP", "1", "2", "3", ""]

        with self.assertRaises(SystemExit) as cm:
            main(arguments)
            if hasattr(cm, "exception") != True:
                self.fail("Exception not raised!")
        self.assertEqual(cm.exception.code, ErrorCodes.EXIT_FAILURE_84)

    @patch('sys.stderr', new_callable=io.StringIO)
    def test_empty_args_operand(self, mock_out):
        arguments = [PROG_NAME] + ["", "1", "2", "3", "4"]

        with self.assertRaises(SystemExit) as cm:
            main(arguments)
            if hasattr(cm, "exception") != True:
                self.fail("Exception not raised!")
        self.assertEqual(cm.exception.code, ErrorCodes.EXIT_FAILURE_84)

    @patch('sys.stdout', new_callable=io.StringIO)
    def test_help_flag_1(self, mock_out):
        expected_output = get_usage()
        arguments = [PROG_NAME] + ["EXP", "1", "2", "3", "4", "-h"]

        with self.assertRaises(SystemExit) as cm:
            main(arguments)
            if hasattr(cm, "exception") == True:
                self.fail("Exception raised!")
            self.assertEqual(cm.exception.code, ErrorCodes.EXIT_SUCCESS)
        self.assertEqual(mock_out.getvalue(), expected_output)

    @patch('sys.stdout', new_callable=io.StringIO)
    def test_help_flag_2(self, mock_out):
        expected_output = get_usage()
        arguments = [PROG_NAME] + ["EXP", "1", "2", "3", "4", "--help"]

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