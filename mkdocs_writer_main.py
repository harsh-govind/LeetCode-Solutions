import sys

from mkdocs_writer import MkdocsWriter

if __name__ == "__main__":
  leetcode_api = MkdocsWriter(sys.argv)
  leetcode_api.write_problems()
  leetcode_api.write_mkdocs()
