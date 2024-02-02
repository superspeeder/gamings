param (
  [switch]$clean = $false
)

if ($clean -and (Test-Path -PathType container "build")) {
  Remove-Item -Recurse -Force build
}

if (!(Test-Path -PathType container "build")) {
  New-Item -Path . -Name "build" -ItemType "directory"
}

Push-Location -Path build

$VCPKG_TOOLCHAIN_LOCATION = [IO.Path]::Combine("$env:USERPROFILE", ".clion-vcpkg", "vcpkg", "scripts", "buildsystems", "vcpkg.cmake")

Invoke-Expression -Command "cmake .. -DCMAKE_EXPORT_COMPILE_COMMANDS=ON -DCMAKE_TOOLCHAIN_FILE=$VCPKG_TOOLCHAIN_LOCATION -G Ninja"

Copy-Item -Path "compile_commands.json" -Destination ..

Pop-Location
