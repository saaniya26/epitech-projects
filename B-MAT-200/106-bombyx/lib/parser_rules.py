class ParserRules:
    arguments: dict = {
        'n': int,
        'k_i0': float,
        'i1': int,
    }
    arguments_count = len(arguments)
    rules: dict[bool | list[bool, int]] = {
        'arg_len_minimum': [True, 1],
        'arg_len_maximum': [True, len(arguments)],
        'arg_len_superior': False,
        'arg_len_exact': False,
        'types_must_match': True,
    }
    help_buffer_path: str = './usage.txt'