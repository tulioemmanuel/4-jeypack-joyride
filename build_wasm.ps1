$path = "./web"

if (-not (Test-Path -Path $path -PathType Container)) {
    New-Item -ItemType Directory -Path $path
}

$cFiles = Get-ChildItem -Filter "*.c" | Select-Object -ExpandProperty Name
& emcc @cFiles -o web/index.html --use-port=sdl3 -s WASM=1



emrun web/index.html