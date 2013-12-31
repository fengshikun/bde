#!/usr/bin/env python
# encoding: utf-8

import os

from waflib import Logs
from waflib.Configure import ConfigurationContext

top = '.'
out = 'build'

def options(ctx):
    import sys

    # check version numbers here because options() is called before any other command-handling function
    if (sys.hexversion < 0x2060000 or 0x3000000 <= sys.hexversion ):
        ctx.fatal('Pyhon 2.6 or Python 2.7 is required to build BDE using waf.')

    ctx.load('bdewscript', tooldir = os.path.join('tools', 'waf', 'bde'))


class PreConfigure(ConfigurationContext):
    cmd = 'configure'

    def __init__(self, **kw):
        global out

        build_dir = os.getenv('BDE_WAF_BUILD_DIR')
        if build_dir:
            out = build_dir

        Logs.debug('config: build dir: ' + out)

        super(PreConfigure, self).__init__(**kw)


def configure(ctx):
    ctx.load('bdewscript', tooldir = os.path.join('tools', 'waf', 'bde'))

def build(ctx):
    ctx.load('bdewscript', tooldir = os.path.join('tools', 'waf', 'bde'))
