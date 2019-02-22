"""
clang compile stage:
    - deriver
    - preprocessing(*.i, *.ii)
    - parsing and semantic analysis(AST)
    - code generation and optimization(LLVM IR, *.s)
    - assembler(*.o)
    - linker(executable or  dynamic library, *.out *.dylib *.so)
"""

import os
import os.path as op
import build

_OUTPUT_FILES = []

# def preprocess():
#     os.system(build.COMPILER + ' -E ' + build.SOURCES[0])

# def parse_to_ast():
#     os.system(build.COMPILER + ' -precompile ' + build.SOURCES[0])

# def ir_generation():
#     os.system(build.COMPILER + ' -emit-llvm ' + build.SOURCES[0])

# def compiler_backend():
#     os.system(build.COMPILER + ' -S ' + build.SOURCES[0])

def assembler():
    if op.exists(build.OUTPUT_DIR) == False:
        os.mkdir(build.OUTPUT_DIR)
    
    for src_path in build.SOURCES:
        src_name_and_suffix = op.basename(src_path).split('.')
        src_basename = src_name_and_suffix[0]
        os.system(build.COMPILER + ' -g -O0 -std=' + build.CXX_STD + ' -I' + build.INCLUDE_PATHS[0] + ' -c ' + src_path + ' -o ' + build.OUTPUT_DIR + '/' + src_basename + '.o')
        _OUTPUT_FILES.append(src_basename + '.o')


def link():
    o_files = ''
    for o_file in _OUTPUT_FILES:
        o_files += build.OUTPUT_DIR + '/' + o_file + ' '

    if len(o_file) > 0:
        os.system(build.COMPILER + ' -g -O0 -std=' + build.CXX_STD + ' ' + o_files + ' -o ' + build.OUTPUT_DIR + '/' + build.TARGET + '.exe')

if __name__ == '__main__':
    assembler()
    link()
