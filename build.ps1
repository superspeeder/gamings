param (
  [switch]$clean = $false
)


if ($clean) {
  Invoke-Expression ".\config.ps1 -clean"
} elseif (!(Test-Path -PathType container "build")) {
  Invoke-Expression ".\config.ps1"
}

Push-Location -Path build

Invoke-Expression "ninja"

Pop-Location
