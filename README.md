# Guía para colaboradores: Configuración Git y Submódulos

Este documento contiene instrucciones para configurar Git correctamente y manejar los submódulos usados en el proyecto (como Eigen), para evitar problemas comunes y facilitar el trabajo en equipo.

---

## 1. Configurar Git para subir ramas nuevas automáticamente

Para evitar tener que usar siempre `git push --set-upstream origin <rama>` al subir una rama nueva, ejecuta este comando una sola vez en tu máquina:

```bash
git config --global push.autoSetupRemote true
````

## 2. Clonar el repositorio con submódulos

Para clonar el repositorio incluyendo todos los submódulos, usa:

```bash
git clone --recurse-submodules https://github.com/marco-prezpad/rpg-concept
````

## 3. Limpieza y reinstalación de submódulos (Eigen)

Si tienes problemas con un submódulo (como Eigen en `libraries/eigen`), sigue estos pasos para limpiarlo y reinstalarlo correctamente.

---

## En sistemas Unix/Linux/macOS

```bash
git submodule deinit -f libraries/Eigen
git rm -f --cached libraries/Eigen
rm -rf libraries/Eigen
rm -rf .git/modules/libraries/Eigen
git submodule add https://gitlab.com/libeigen/eigen.git libraries/eigen
git submodule update --init --recursive
````

## Nota para usuarios Windows sobre limpieza de submódulos

Cuando en las instrucciones de limpieza se indica usar:

```bash
rm -rf libraries/Eigen
rm -rf .git/modules/libraries/Eigen
````
En Windows Powershell debe sustituirse por

````Powershell
rd /s /q libraries\Eigen
Remove-Item -Recurse -Force .git\modules\libraries\Eigen
````
