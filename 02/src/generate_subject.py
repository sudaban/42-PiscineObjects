import matplotlib.pyplot as plt
import matplotlib.patches as mpatches
from matplotlib.patches import FancyArrowPatch, Polygon, Rectangle
from matplotlib.lines import Line2D
import numpy as np
import os


CLASS_EDGE = "#1F1F1F"
HEADER_FILL = "#D9E7F5"
CLASS_FILL = "#FFFDF5"
INTERFACE_FILL = "#F5E7D9"
INTERFACE_HEADER = "#E7C8A8"
ABSTRACT_FILL = "#EFE9F7"
ABSTRACT_HEADER = "#C8B5DC"
CAR_HEADER = "#F2D7D5"
INK = "#1F1F1F"


def DrawClassBox(ax, x, y, w, h, title, members, header_fill=HEADER_FILL, body_fill=CLASS_FILL,
                 italic_title=False, abstract=False, interface=False):
    header_h = 0.55
    box = Rectangle((x, y), w, h, linewidth=1.4, edgecolor=CLASS_EDGE, facecolor=body_fill, zorder=2)
    ax.add_patch(box)
    header = Rectangle((x, y + h - header_h), w, header_h, linewidth=0, facecolor=header_fill, zorder=3)
    ax.add_patch(header)
    ax.plot([x, x + w], [y + h - header_h, y + h - header_h], color=CLASS_EDGE, linewidth=1.0, zorder=4)
    if interface:
        title_disp = f"«interface»\n{title}"
    elif abstract:
        title_disp = f"«abstract»\n{title}"
    else:
        title_disp = title
    ax.text(x + w / 2, y + h - header_h / 2, title_disp,
            ha="center", va="center", fontsize=9.5, fontweight="bold",
            style="italic" if (italic_title or interface or abstract) else "normal",
            color=INK, zorder=5)
    if members:
        body_top = y + h - header_h
        body_h = h - header_h
        n = len(members)
        row_h = body_h / (n + 1)
        for i, m in enumerate(members):
            line_y = body_top - row_h * (i + 1)
            ax.text(x + 0.12, line_y, m, ha="left", va="center", fontsize=8.0, color=INK, zorder=5)
            if i < n - 1:
                sep_y = body_top - row_h * (i + 1.5)
                ax.plot([x + 0.05, x + w - 0.05], [sep_y, sep_y],
                        color="#A8A8A8", linewidth=0.5, linestyle="--", zorder=4)
    return {
        "x": x, "y": y, "w": w, "h": h,
        "left_mid": (x, y + h / 2), "right_mid": (x + w, y + h / 2),
        "top_mid": (x + w / 2, y + h), "bottom_mid": (x + w / 2, y),
        "tl": (x, y + h), "tr": (x + w, y + h), "bl": (x, y), "br": (x + w, y),
    }


def DrawInheritance(ax, p1, p2):
    arr = FancyArrowPatch(p1, p2, arrowstyle="-|>", mutation_scale=18,
                          linewidth=1.3, color=INK, zorder=6)
    ax.add_patch(arr)


def _Diamond(ax, origin, direction, size, filled):
    direction = np.array(direction, dtype=float)
    norm = np.linalg.norm(direction)
    if norm == 0:
        return None
    direction /= norm
    perp = np.array([-direction[1], direction[0]])
    d = size
    p1 = np.array(origin) + d * direction
    p2 = p1 + d * perp
    p3 = p1 - d * perp
    fc = INK if filled else "white"
    poly = Polygon([p1, p2, np.array(origin, dtype=float), p3], closed=True,
                   facecolor=fc, edgecolor=INK, zorder=7)
    ax.add_patch(poly)
    return p1


def DrawComposition(ax, p1, p2, label=None, label_pos=None):
    p1 = np.array(p1, dtype=float)
    p2 = np.array(p2, dtype=float)
    direction = p2 - p1
    norm = np.linalg.norm(direction)
    if norm == 0:
        return
    direction /= norm
    back = _Diamond(ax, p1, direction, size=0.20, filled=True)
    start = back if back is not None else p1
    ax.plot([start[0], p2[0]], [start[1], p2[1]], color=INK, linewidth=1.2, zorder=4)
    if label:
        mid = ((start[0] + p2[0]) / 2, (start[1] + p2[1]) / 2)
        if label_pos is None:
            label_pos = mid
        ax.text(label_pos[0], label_pos[1], label, ha="center", va="center",
                fontsize=8.5, color=INK, zorder=8,
                bbox=dict(facecolor="white", edgecolor="none", pad=1.5))


def DrawAggregation(ax, p1, p2, label=None, label_pos=None):
    p1 = np.array(p1, dtype=float)
    p2 = np.array(p2, dtype=float)
    direction = p2 - p1
    norm = np.linalg.norm(direction)
    if norm == 0:
        return
    direction /= norm
    back = _Diamond(ax, p1, direction, size=0.22, filled=False)
    start = back if back is not None else p1
    ax.plot([start[0], p2[0]], [start[1], p2[1]], color=INK, linewidth=1.2, zorder=4)
    if label:
        mid = ((start[0] + p2[0]) / 2, (start[1] + p2[1]) / 2)
        if label_pos is None:
            label_pos = mid
        ax.text(label_pos[0], label_pos[1], label, ha="center", va="center",
                fontsize=8.5, color=INK, zorder=8,
                bbox=dict(facecolor="white", edgecolor="none", pad=1.5))


def DrawAssociation(ax, p1, p2, label=None, label_pos=None, mult_a=None, mult_b=None, arrow=True):
    style = "->" if arrow else "-"
    arr = FancyArrowPatch(p1, p2, arrowstyle=style, mutation_scale=14,
                          linewidth=1.1, color=INK, zorder=4)
    ax.add_patch(arr)
    if mult_a:
        ax.text(p1[0] + 0.18, p1[1] + 0.10, mult_a, ha="left", va="center",
                fontsize=8.2, color=INK, zorder=8,
                bbox=dict(facecolor="white", edgecolor="none", pad=1))
    if mult_b:
        ax.text(p2[0] - 0.18, p2[1] - 0.10, mult_b, ha="right", va="center",
                fontsize=8.2, color=INK, zorder=8,
                bbox=dict(facecolor="white", edgecolor="none", pad=1))
    if label:
        mid = ((p1[0] + p2[0]) / 2, (p1[1] + p2[1]) / 2)
        if label_pos is None:
            label_pos = mid
        ax.text(label_pos[0], label_pos[1], label, ha="center", va="center",
                fontsize=8.5, color=INK, zorder=8,
                bbox=dict(facecolor="white", edgecolor="none", pad=1.5))


def Shift(p, dx=0.0, dy=0.0):
    return (p[0] + dx, p[1] + dy)


fig_w, fig_h = 28, 19
fig, ax = plt.subplots(figsize=(fig_w, fig_h), dpi=140)
ax.set_xlim(0, fig_w)
ax.set_ylim(0, fig_h)
ax.set_aspect("equal")
ax.axis("off")
fig.patch.set_facecolor("white")


C_W = 3.8
C_H = 2.2


linkable = DrawClassBox(ax, 0.5, 16.2, C_W, C_H, "LinkablePart",
                        ["+ Execute(pression: float): void"],
                        INTERFACE_HEADER, INTERFACE_FILL, interface=True)

injector = DrawClassBox(ax, 0.5, 12.0, C_W, C_H + 0.2, "Injector",
                        ["- m_chamber: ExplosionChamber*", "+ Execute(pression: float): void"])

chamber = DrawClassBox(ax, 0.5, 8.0, C_W, C_H, "ExplosionChamber",
                       ["- m_crankshaft: Crankshaft*", "+ Fill(volume: float): void"])

crankshaft = DrawClassBox(ax, 0.5, 4.0, C_W, C_H, "Crankshaft",
                          ["- m_transmission: Transmission*", "+ ReceiveForce(volume: float): void"])

transmission = DrawClassBox(ax, 5.6, 0.5, C_W, C_H, "Transmission",
                            ["- m_wheels: vector<Wheel*>", "+ Activate(force: float): void"])

wheel = DrawClassBox(ax, 10.9, 0.5, C_W, C_H, "Wheel",
                     ["+ ExecuteRotation(force: float): void"])

gear = DrawClassBox(ax, 16.8, 0.5, C_W, C_H, "Gear",
                    ["- m_demultiplier: int"])

brake_controller = DrawClassBox(ax, 5.6, 16.2, C_W, C_H, "BrakeController",
                                ["- m_brakes: Brake[]", "+ Execute(pression: float): void"])

brake = DrawClassBox(ax, 5.6, 12.0, C_W, C_H, "Brake",
                     ["- m_wheel: Wheel*", "+ Execute(force: float): void",
                      "+ AttackWheel(wheel: Wheel*): void"])

pedal = DrawClassBox(ax, 10.9, 16.2, C_W, C_H, "Pedal",
                     ["- m_target: LinkablePart*", "+ SetTarget(part: LinkablePart*): void",
                      "+ Use(pression: float): void"])

direction = DrawClassBox(ax, 10.9, 12.0, C_W, C_H, "Direction",
                         ["- m_wheels: Wheel[]", "+ Turn(angle: float): void"])

dae = DrawClassBox(ax, 10.9, 8.0, C_W, C_H, "DAE",
                   ["- m_direction: Direction*", "- m_force: float",
                    "+ Use(angle: float): void"])

steer_wheel = DrawClassBox(ax, 10.9, 4.0, C_W, C_H, "SteerWheel",
                           ["- m_dae: DAE*", "+ Turn(angle: float): void"])

gear_lever = DrawClassBox(ax, 16.8, 16.2, C_W, C_H, "GearLever",
                          ["- m_gears: Gear[]", "- m_level: int",
                           "+ Change(): void", "+ ActiveGear(): Gear*"],
                          ABSTRACT_HEADER, ABSTRACT_FILL, italic_title=True)

singleton = DrawClassBox(ax, 16.8, 11.7, C_W, C_H, "Singleton<GearLever>",
                         ["+ GetInstance(): GearLever*"],
                         ABSTRACT_HEADER, ABSTRACT_FILL, italic_title=True, abstract=True)

cockpit = DrawClassBox(ax, 16.8, 7.4, C_W, C_H + 0.6, "Cockpit",
                       ["- m_pedal: Pedal", "- m_steerWheel: SteerWheel",
                        "- m_gearLever: GearLever", "+ manage(): void"])

electronics = DrawClassBox(ax, 16.8, 3.7, C_W, C_H, "Electronics",
                           ["- m_dae: DAE"])

motor = DrawClassBox(ax, 0.5, 0.5, C_W, C_H, "Motor",
                     ["- m_injectors: Injector[]", "- m_chamber: ExplosionChamber",
                      "- m_crankshaft: Crankshaft",
                      "+ ConnectToTransmission(transmission: Transmission*): void"])

car = DrawClassBox(ax, 22.5, 7.5, C_W + 0.6, C_H + 1.2, "Car",
                   ["- m_brakeController: BrakeController", "- m_direction: Direction",
                    "- m_transmission: Transmission", "- m_motor: Motor",
                    "- m_electronics: Electronics", "- m_cockpit: Cockpit"],
                   CAR_HEADER)


DrawInheritance(ax, injector["top_mid"], linkable["bottom_mid"])
DrawInheritance(ax, brake_controller["top_mid"], Shift(linkable["bottom_mid"], 1.4, 0.0))
DrawInheritance(ax, gear_lever["bottom_mid"], singleton["top_mid"])


DrawAssociation(ax, Shift(injector["right_mid"], 0.0, -0.3),
                Shift(chamber["top_mid"], 0.0, 0.15), label="chamber")
DrawAssociation(ax, chamber["bottom_mid"], crankshaft["top_mid"], label="crankshaft")
DrawAssociation(ax, Shift(crankshaft["right_mid"], 0.05, 0.15),
                Shift(transmission["top_mid"], 0.0, 0.15), label="transmission")
DrawAggregation(ax, transmission["right_mid"], wheel["left_mid"],
                label="wheels", label_pos=(8.6, 1.6))
DrawAggregation(ax, brake_controller["right_mid"], Shift(brake["top_mid"], 0.0, 0.2),
                label="brakes", label_pos=(7.6, 14.0))
DrawAssociation(ax, Shift(brake["right_mid"], 0.05, -0.1),
                Shift(wheel["top_mid"], 0.3, 0.2), label="wheel")
DrawAssociation(ax, pedal["bottom_mid"], Shift(linkable["right_mid"], 0.05, 0.0), label="target")
DrawAggregation(ax, direction["right_mid"], Shift(wheel["top_mid"], -0.4, 0.2),
                label="wheels", label_pos=(13.0, 12.6))
DrawComposition(ax, dae["left_mid"], direction["right_mid"], label="direction")
DrawAssociation(ax, steer_wheel["right_mid"], Shift(dae["left_mid"], 0.05, 0.4), label="dae")
DrawAssociation(ax, gear_lever["left_mid"], Shift(gear["right_mid"], 0.05, 0.2), label="gears")
DrawAggregation(ax, Shift(cockpit["right_mid"], 0.0, 0.2),
                Shift(gear_lever["left_mid"], 0.05, -0.2),
                label="gearLever", label_pos=(20.4, 12.0))
DrawAggregation(ax, Shift(cockpit["left_mid"], 0.0, 0.2),
                Shift(steer_wheel["right_mid"], 0.05, 0.2),
                label="steerWheel", label_pos=(14.0, 12.0))
DrawAggregation(ax, Shift(cockpit["left_mid"], -0.4, -0.2),
                Shift(pedal["right_mid"], 0.0, -0.2),
                label="pedal", label_pos=(14.0, 14.2))
DrawAggregation(ax, electronics["top_mid"], Shift(dae["right_mid"], 0.05, -0.4),
                label="dae", label_pos=(18.6, 9.0))
DrawAssociation(ax, Shift(motor["right_mid"], 0.0, 0.2),
                Shift(transmission["left_mid"], -0.05, 0.3),
                label="connectToTransmission", arrow=True)
DrawComposition(ax, Shift(car["left_mid"], 0.0, 0.4),
                Shift(motor["right_mid"], 0.05, 0.2),
                label="motor", label_pos=(20.6, 2.0))
DrawComposition(ax, Shift(car["left_mid"], 0.2, -0.6),
                Shift(electronics["right_mid"], 0.05, -0.2),
                label="electronics", label_pos=(20.6, 5.5))
DrawComposition(ax, Shift(car["left_mid"], -0.2, -0.2),
                Shift(cockpit["right_mid"], 0.05, -0.2),
                label="cockpit", label_pos=(20.6, 8.5))
DrawComposition(ax, Shift(car["bottom_mid"], -0.4, 0.0),
                Shift(brake_controller["right_mid"], 0.05, -0.5),
                label="brakeController", label_pos=(15.0, 13.0))
DrawComposition(ax, Shift(car["bottom_mid"], 0.4, 0.0),
                Shift(direction["right_mid"], 0.4, -0.4),
                label="direction", label_pos=(17.0, 10.4))
DrawComposition(ax, Shift(car["bottom_mid"], -0.1, 0.0),
                Shift(transmission["top_mid"], 0.4, 0.1),
                label="transmission", label_pos=(13.0, 4.2))


title = "UML Class Diagram — Car Composition (Piscine Object / Module 02 — Exercise 00)"
ax.text(fig_w / 2, fig_h - 0.35, title, ha="center", va="top",
        fontsize=15, fontweight="bold", color=INK)

legend_items = [
    Line2D([0], [0], color=INK, lw=1.3, label="Association"),
    Line2D([0], [0], color=INK, lw=1.3, linestyle=(0, (4, 2)), label="Realization (dashed)"),
    Line2D([0], [0], color=INK, lw=1.3, label="Inheritance (solid)"),
    mpatches.Patch(facecolor=INK, edgecolor=INK, label="Composition ◆"),
    mpatches.Patch(facecolor="white", edgecolor=INK, label="Aggregation ◇"),
]
leg = ax.legend(handles=legend_items, loc="lower left",
                bbox_to_anchor=(0.0, -0.03), frameon=True, fontsize=9, ncol=5)
leg.set_zorder(10)

plt.tight_layout()
os.makedirs("ex00", exist_ok=True)
plt.savefig("ex00/subject.png", dpi=160, bbox_inches="tight", facecolor="white")
plt.close(fig)
print("Mandatory diagram written to ex00/subject.png")
