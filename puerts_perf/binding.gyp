{
  "targets": [
    {
      "target_name": "puerts_perf",
      'include_dirs': [
        "<!@(node -p \"require('puerts').include_dir\")",
      ],
      "defines": [ "BUILDING_PES_EXTENSION"],
      "sources": [ "src/puerts_perf.cc", "<!@(node -p \"require('puerts').src_dir\")/pesapi_adpt.c" ]
    }
  ]
} 
