$env:NUM_CORES = (Get-CimInstance Win32_ComputerSystem).NumberOfLogicalProcessors
cmake-js compile --parallel $env:NUM_CORES
tsc