#!/usr/bin/python3
import sys
from lib.parser import Parser
from lib.parser_rules import ParserRules
from lib.macros import ErrorCodes, check_type
from lib.calculator import BombyxCalcMode, BombyxCalculator

def main(argv: list[str]):
    ## Parser
    parser = Parser(
        ParserRules.arguments_count,
        argv,
        ParserRules.arguments,
        ParserRules.rules,
        ParserRules.help_buffer_path
    )

    # Program Args
    arguments = parser.check_arguments()

    ## Program Exec
    try:
        calculator: BombyxCalculator = None

        mode: BombyxCalcMode = BombyxCalcMode.UNKN_MODE
        data_set: list = None
        if (arguments['k_i0'] == None):
            mode = BombyxCalcMode.DEFAULT_MODE
            data_set = [arguments['n']]
        if (arguments['k_i0'] != None and arguments['i1'] == None):
            mode = BombyxCalcMode.K_MODE
            data_set = [arguments['n'], arguments['k_i0']]
        if (arguments['k_i0'] != None and arguments['i1'] != None
            and check_type(arguments['k_i0'], int) and check_type(arguments['i1'], int)):
            mode = BombyxCalcMode.I0_I1_MODE
            data_set = [arguments['n'], arguments['k_i0'], arguments['i1']]

        calculator = BombyxCalculator(mode, data_set)
        calculator.exec_calculation()
    except Exception as e:
        print(f"(Error)\nUnknown failure.\nTraceback:\n{e}")
        exit(ErrorCodes.EXIT_FAILURE_84)
    exit(ErrorCodes.EXIT_SUCCESS)

if (__name__ == '__main__'):
    main(sys.argv[1:])
