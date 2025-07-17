from unittest.mock import patch
from lib.macros import ErrorCodes
from main import main
import unittest
import sys
import io

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
        arguments = ["0*1*2*3*4", "1"]

        with self.assertRaises(SystemExit) as cm:
            main(arguments)
            if hasattr(cm, "exception") == True:
                self.fail("Exception raised!")
        self.assertEqual(cm.exception.code, ErrorCodes.EXIT_SUCCESS)

    @patch('sys.stdout', new_callable=io.StringIO)
    def test_help_flag_1(self, mock_out):
        expected_output = get_usage()
        arguments = ["-h"]

        with self.assertRaises(SystemExit) as cm:
            main(arguments)
            if hasattr(cm, "exception") == True:
                self.fail("Exception raised!")
        self.assertEqual(cm.exception.code, ErrorCodes.EXIT_SUCCESS)
        self.assertEqual(mock_out.getvalue(), expected_output)

    @patch('sys.stdout', new_callable=io.StringIO)
    def test_help_flag_2(self, mock_out):
        expected_output = get_usage()
        arguments = ["--help"]

        with self.assertRaises(SystemExit) as cm:
            main(arguments)
            if hasattr(cm, "exception") == True:
                self.fail("Exception raised!")
        self.assertEqual(cm.exception.code, ErrorCodes.EXIT_SUCCESS)
        self.assertEqual(mock_out.getvalue(), expected_output)

class TestArguments_InitInvalid(unittest.TestCase):
    @patch('sys.stderr', new_callable=io.StringIO)
    def test_div_zero(self, mock_out):
        arguments = ["0*1*2*3*4", "0"]

        with self.assertRaises(SystemExit) as cm:
            main(arguments)
            if hasattr(cm, "exception") != True:
                self.fail("Exception not raised!")
        self.assertEqual(cm.exception.code, ErrorCodes.EXIT_FAILURE_84)

    @patch('sys.stderr', new_callable=io.StringIO)
    def test_missing_num_left(self, mock_out):
        arguments = ["*1*2*3*4", "1"]

        with self.assertRaises(SystemExit) as cm:
            main(arguments)
            if hasattr(cm, "exception") != True:
                self.fail("Exception not raised!")
        self.assertEqual(cm.exception.code, ErrorCodes.EXIT_FAILURE_84)

    @patch('sys.stderr', new_callable=io.StringIO)
    def test_missing_num_right(self, mock_out):
        arguments = ["0*1*2*3*", "1"]

        with self.assertRaises(SystemExit) as cm:
            main(arguments)
            if hasattr(cm, "exception") != True:
                self.fail("Exception not raised!")
        self.assertEqual(cm.exception.code, ErrorCodes.EXIT_FAILURE_84)

    @patch('sys.stderr', new_callable=io.StringIO)
    def test_letters_in_data_left(self, mock_out):
        arguments = ["0*1*2gibberish*3*4", "1"]

        with self.assertRaises(SystemExit) as cm:
            main(arguments)
            if hasattr(cm, "exception") != True:
                self.fail("Exception not raised!")
        self.assertEqual(cm.exception.code, ErrorCodes.EXIT_FAILURE_84)

    @patch('sys.stderr', new_callable=io.StringIO)
    def test_letters_in_data_right(self, mock_out):
        arguments = ["0*1*2*3*4", "1gibberish"]

        with self.assertRaises(SystemExit) as cm:
            main(arguments)
            if hasattr(cm, "exception") != True:
                self.fail("Exception not raised!")
        self.assertEqual(cm.exception.code, ErrorCodes.EXIT_FAILURE_84)

    @patch('sys.stderr', new_callable=io.StringIO)
    def test_missing_denominator_1(self, mock_out):
        arguments = ["0*1*2*3*4"]

        with self.assertRaises(SystemExit) as cm:
            main(arguments)
            if hasattr(cm, "exception") != True:
                self.fail("Exception not raised!")
        self.assertEqual(cm.exception.code, ErrorCodes.EXIT_FAILURE_84)

    @patch('sys.stderr', new_callable=io.StringIO)
    def test_missing_denominator_2(self, mock_out):
        arguments = ["0*1*2*3*4", "1", "4*3*2*1*0"]

        with self.assertRaises(SystemExit) as cm:
            main(arguments)
            if hasattr(cm, "exception") != True:
                self.fail("Exception not raised!")
        self.assertEqual(cm.exception.code, ErrorCodes.EXIT_FAILURE_84)

    @patch('sys.stderr', new_callable=io.StringIO)
    def test_empty_arg_1(self, mock_out):
        arguments = ["", "1"]

        with self.assertRaises(SystemExit) as cm:
            main(arguments)
            if hasattr(cm, "exception") != True:
                self.fail("Exception not raised!")
        self.assertEqual(cm.exception.code, ErrorCodes.EXIT_FAILURE_84)

    @patch('sys.stderr', new_callable=io.StringIO)
    def test_empty_arg_2(self, mock_out):
        arguments = ["0*1*2*3*4", ""]

        with self.assertRaises(SystemExit) as cm:
            main(arguments)
            if hasattr(cm, "exception") != True:
                self.fail("Exception not raised!")
        self.assertEqual(cm.exception.code, ErrorCodes.EXIT_FAILURE_84)

    @patch('sys.stderr', new_callable=io.StringIO)
    def test_empty_arg_3(self, mock_out):
        arguments = ["0*1*2*3*4", "1", "", "2"]

        with self.assertRaises(SystemExit) as cm:
            main(arguments)
            if hasattr(cm, "exception") != True:
                self.fail("Exception not raised!")
        self.assertEqual(cm.exception.code, ErrorCodes.EXIT_FAILURE_84)

    @patch('sys.stderr', new_callable=io.StringIO)
    def test_empty_arg_4(self, mock_out):
        arguments = ["0*1*2*3*4", "1", "4*3*2*1*0", ""]

        with self.assertRaises(SystemExit) as cm:
            main(arguments)
            if hasattr(cm, "exception") != True:
                self.fail("Exception not raised!")
        self.assertEqual(cm.exception.code, ErrorCodes.EXIT_FAILURE_84)

    @patch('sys.stderr', new_callable=io.StringIO)
    def test_empty_arg_5(self, mock_out):
        arguments = ["", "", "4*3*2*1*0", "2"]

        with self.assertRaises(SystemExit) as cm:
            main(arguments)
            if hasattr(cm, "exception") != True:
                self.fail("Exception not raised!")
        self.assertEqual(cm.exception.code, ErrorCodes.EXIT_FAILURE_84)

    @patch('sys.stderr', new_callable=io.StringIO)
    def test_empty_arg_6(self, mock_out):
        arguments = ["0*1*2*3*4", "1", "", ""]

        with self.assertRaises(SystemExit) as cm:
            main(arguments)
            if hasattr(cm, "exception") != True:
                self.fail("Exception not raised!")
        self.assertEqual(cm.exception.code, ErrorCodes.EXIT_FAILURE_84)

    @patch('sys.stderr', new_callable=io.StringIO)
    def test_empty_arg_7(self, mock_out):
        arguments = ["", "", "", ""]

        with self.assertRaises(SystemExit) as cm:
            main(arguments)
            if hasattr(cm, "exception") != True:
                self.fail("Exception not raised!")
        self.assertEqual(cm.exception.code, ErrorCodes.EXIT_FAILURE_84)

    @patch('sys.stdout', new_callable=io.StringIO)
    def test_help_flag_1(self, mock_out):
        expected_output = get_usage()
        arguments = ["0*1*2*3*4", "0", "-h"]

        with self.assertRaises(SystemExit) as cm:
            main(arguments)
            if hasattr(cm, "exception") == True:
                self.fail("Exception raised!")
            self.assertEqual(cm.exception.code, ErrorCodes.EXIT_SUCCESS)
        self.assertEqual(mock_out.getvalue(), expected_output)

    @patch('sys.stdout', new_callable=io.StringIO)
    def test_help_flag_2(self, mock_out):
        expected_output = get_usage()
        arguments = ["0*1*2*3*4", "0", "--help"]

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