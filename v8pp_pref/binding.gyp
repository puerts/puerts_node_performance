{
	'targets':
	[
		{
			'target_name': 'v8pp_pref',
			'include_dirs': [
              "node_modules/v8pp"
            ],
			'cflags_cc': ['-std=c++17', '-fexceptions'],
			'msvs_settings': { 'VCCLCompilerTool': { 'ExceptionHandling': 1, 'AdditionalOptions': ['/std:c++17'] } },
			'xcode_settings': { 'GCC_ENABLE_CPP_EXCEPTIONS': 'YES', 'OTHER_CFLAGS': ['-std=c++17'] },
            'defines': [ 'V8PP_HEADER_ONLY=1'],
			'sources': ['src/v8pp_pref.cc'],
		}
	]
}