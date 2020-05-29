#!/usr/bin/env python2
# SPDX-License-Identifier: GPL-3.0-or-later
# devicetree_convert Tool to convert a DTB to a static C file

from pyfdt.pyfdt import FdtBlobParse
import argparse

parser = argparse.ArgumentParser(description='Cavium DTB to C converter')
parser.add_argument('--indtb', help='Compiled devicetree blob to parse')
parser.add_argument('--out', help='The file to write')
parser.add_argument('--verbose', help='Be verbose', action='store_true', default=False)
args = parser.parse_args()

outfile = None
if args.out is not None:
    outfile = open(args.out, 'w')
    outfile.write("// This file is automatically generated.\n")
    outfile.write("// DO NOT EDIT BY HAND.\n\n")
    outfile.write("#include <bdk-devicetree.h>\n\n")
    outfile.write("const struct bdk_devicetree_key_value devtree[] = {\n")

with open(args.indtb) as infile:
    dtb = FdtBlobParse(infile)
    fdt = dtb.to_fdt()
    for (path, node) in fdt.resolve_path('/cavium,bdk').walk():
        if "/" in path:
            path = path.replace("/", "")
        if len(node) == 1:
            for i in node:
                if type(i) is not unicode:
                    print "%s: Type is not string" % path
                    continue
                if args.verbose:
                    print "%s = %s" % (path, i)
                if outfile is not None:
                    outfile.write("{\"%s\", \"%s\"},\n" % (path, i))
        else:
            print "%s: Arrays aren't supported" % path

if outfile is not None:
    outfile.write("{0, 0},\n")
    outfile.write("};\n")
