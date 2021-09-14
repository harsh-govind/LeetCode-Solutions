from dataclasses import dataclass
from typing import List

from dataclass_wizard import JSONWizard


@dataclass
class TopicTag:
  name: str


@dataclass
class Problem(JSONWizard):
  title: str
  difficulty: str
  likes: int
  dislikes: int
  topicTags: List[TopicTag]
