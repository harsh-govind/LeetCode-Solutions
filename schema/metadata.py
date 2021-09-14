from dataclasses import dataclass
from typing import Any, List, Optional

from dataclass_wizard import JSONWizard


@dataclass
class Stat:
  question_id: int
  question__article__live: Optional[bool]
  question__article__slug: Optional[str]
  question__article__has_video_solution: Optional[bool]
  question__title: str
  question__title_slug: str
  question__hide: bool
  total_acs: int
  total_submitted: int
  frontend_question_id: int
  is_new_question: bool


@dataclass
class Difficulty:
  level: int


@dataclass
class StatStatusPair:
  stat: Stat
  status: Any
  difficulty: Difficulty
  paid_only: bool
  is_favor: bool
  frequency: int
  progress: int


@dataclass
class Metadata(JSONWizard):
  user_name: str
  num_solved: int
  num_total: int
  ac_easy: int
  ac_medium: int
  ac_hard: int
  stat_status_pairs: List[StatStatusPair]
  frequency_high: int
  frequency_mid: int
  category_slug: str
