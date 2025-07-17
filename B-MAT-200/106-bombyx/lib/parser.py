from lib.macros import ErrorCodes

class Parser:
    def __init__(self, argc: int, argv: list,
                 argv_id: dict, rules: dict | None, help_buff_path: str | None) -> None:
        self.__argc: int = argc
        self.__total_argc: int = len(argv)
        self.argv: list = argv
        self.arguments: dict[str, str] = {}
        self.__argv_id: dict[str, type] = argv_id
        self.help_buff_path: str | None = help_buff_path
        self.rules: dict[str, bool] = rules

        i: int = 0
        try:
            keys = list(argv_id.keys())
            for i in range(len(keys)):
                self.arguments[keys[i]] = None
            try:
                for i in range(len(argv)):
                    self.arguments[keys[i]] = argv[i]
            except IndexError:
                pass
        except Exception as e:
            print(f"(Error)\nUnknown failure.\nTraceback:\n${e}")
            exit(ErrorCodes.EXIT_FAILURE_84)

    def show_help(self) -> None:
        try:
            fd = open(self.help_buff_path)
            print(fd.read())
            fd.close()
            exit(ErrorCodes.EXIT_SUCCESS)
        except Exception as e:
            print(f"(Error)\nUnknown failure.\nTraceback:\n${e}")
            exit(ErrorCodes.EXIT_FAILURE_84)

    def check_if_needs_help(self) -> bool:
        for element in self.argv:
            if (element == '-h' or element == '--help'):
                self.show_help()
                exit(ErrorCodes.EXIT_SUCCESS)

    def check_arguments(self) -> dict[str, str]:
        try:
            self.check_if_needs_help()

            if (self.rules['arg_len_superior'] == True and self.__total_argc < self.__argc):
                print(f"(Error)\nInvalid number of arguments.\nExpected args count equal or above '{self.__argc}' not '{len(self.arguments)}'")
                exit(ErrorCodes.EXIT_FAILURE_84)

            if (self.rules['arg_len_exact'] == True and self.__total_argc != self.__argc):
                print(f"(Error)\nInvalid number of arguments.\nExpected length '{self.__argc}' not '{self.__total_argc}'")
                exit(ErrorCodes.EXIT_FAILURE_84)

            if (self.rules['arg_len_minimum'][0] == True and self.__total_argc < self.rules['arg_len_minimum'][1]):
                print(f"(Error)\nInvalid number of arguments.\nExpected minimal length '{self.rules['arg_len_minimum'][1]}' not '{self.__total_argc}'")
                exit(ErrorCodes.EXIT_FAILURE_84)

            if (self.rules['arg_len_maximum'][0] == True and self.__total_argc > self.rules['arg_len_maximum'][1]):
                print(f"(Error)\nInvalid number of arguments.\nExpected maximum length '{self.rules['arg_len_maximum'][1]}' not '{self.__total_argc}'")
                exit(ErrorCodes.EXIT_FAILURE_84)


            if (self.rules['types_must_match']):
                for key in self.__argv_id.keys():
                    try:
                        self.__argv_id[key](self.arguments[key])
                        self.__argv_id[key].__name__
                    except ValueError:
                        print(f"(Error)\nInvalid type inserted at key '{self.arguments[key]}'.\nExpected '{str(self.__argv_id[key].__name__)}' not 'Unknown Type: {self.arguments[key]}'")
                        exit(ErrorCodes.EXIT_FAILURE_84)
                    except TypeError:
                        if (self.arguments[key] == None and self.rules['arg_len_exact'] == False):
                            continue
                    arg_type_conv = type(self.__argv_id[key](self.arguments[key])).__name__
                    arg_rule_type_conv = self.__argv_id[key].__name__
                    if arg_type_conv != arg_rule_type_conv:
                        print(f"(Error)\nInvalid type inserted at key '{self.arguments[key]}'.\nExpected '{str(self.__argv_id[key].__name__)}' not '{type(self.arguments[key]).__name__}'")
                        exit(ErrorCodes.EXIT_FAILURE_84)
            return self.arguments

        except Exception as e:
            raise e
            print(f"(Error)\nUnknown failure.\nTraceback:\n{e}")
            exit(ErrorCodes.EXIT_FAILURE_84)