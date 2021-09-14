#!/bin/bash

git clone -b main https://github.com/walkccc/LeetCode.git main
git clone -b mkdocs --single-branch https://github.com/walkccc/LeetCode.git mkdocs
git clone -b scripts --single-branch https://github.com/walkccc/LeetCode.git scripts

python3 scripts/readme_writer_main.py
python3 scripts/mkdocs_writer_main.py --mock

cp main/README.md mkdocs/docs/index.md
cp main/STYLEGUIDE.md mkdocs/docs/styleguide.md

mkdocs serve -f mkdocs/mkdocs.yml
