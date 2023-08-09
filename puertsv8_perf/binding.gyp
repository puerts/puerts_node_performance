{
  "targets": [
    {
      "target_name": "puertsv8_perf",
      'include_dirs': [
        "<!@(node -p \"require('puerts').include_dir\")",
      ],
      "defines": [ "BUILDING_PES_EXTENSION", "PES_EXTENSION_WITH_V8_API"],
      "sources": [ "src/puertsv8_perf.cc", "<!@(node -p \"require('puerts').src_dir\")/pesapi_adpt.c" ]
    }
  ]
} 
